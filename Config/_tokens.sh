#! /bin/bash -e
###########################################################################
#                                                                         #
# Copyright 2019 INTERSEC SA                                              #
#                                                                         #
# Licensed under the Apache License, Version 2.0 (the "License");         #
# you may not use this file except in compliance with the License.        #
# You may obtain a copy of the License at                                 #
#                                                                         #
#     http://www.apache.org/licenses/LICENSE-2.0                          #
#                                                                         #
# Unless required by applicable law or agreed to in writing, software     #
# distributed under the License is distributed on an "AS IS" BASIS,       #
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.#
# See the License for the specific language governing permissions and     #
# limitations under the License.                                          #
#                                                                         #
###########################################################################

die() {
    echo "$@" 1>&2
    exit 2
}

do_hdr() {
    cat <<EOF
/*****     THIS FILE IS AUTOGENERATED DO NOT MODIFY DIRECTLY !    *****/

EOF
}

do_h() {
    cat <<EOF
`do_hdr`
#ifndef IS_${UPPERCASE_NAME}_TOKENS_H
#define IS_${UPPERCASE_NAME}_TOKENS_H

#include <lib-common/core.h>

enum ${LOWERCASE_NAME}_token {
    ${UPPERCASE_NAME}_TK_unknown,
`tr 'a-z-./ ' 'A-Z____' | sed -e "s/^[^/].*/    ${UPPERCASE_NAME}_TK_&,/"`
};

__attribute__((pure))
enum ${LOWERCASE_NAME}_token
${LOWERCASE_NAME}_get_token(const char *s, int len);

__attribute__((pure))
enum ${LOWERCASE_NAME}_token
${LOWERCASE_NAME}_get_token_ps(pstream_t ps);

static ALWAYS_INLINE enum ${LOWERCASE_NAME}_token
${LOWERCASE_NAME}_get_token_lstr(lstr_t s)
{
    return ${LOWERCASE_NAME}_get_token(s.s, s.len);
}
#endif /* IS_${UPPERCASE_NAME}_TOKEN_H */
EOF
}

do_tokens() {
    while read tok; do
        case "$tok" in
            "") continue;;
            *)
                echo "$tok, ${UPPERCASE_NAME}_TK_`echo $tok | tr 'a-z-./ ' 'A-Z____'`"
                ;;
        esac
    done
}

version_ge() {
    test "$(echo "$@" | tr " " "\n" | sort -rV | head -n 1)" == "$1"
}

do_function_decl() {
    gperf_ver=$(gperf -v | head -n1 | cut -d' ' -f3)

    if version_ge $gperf_ver "3.1"; then
        cat <<EOF
static const struct tok *
${LOWERCASE_NAME}_get_token_aux(register const char *str, register size_t len);
EOF
    else
        cat <<EOF
static const struct tok *
${LOWERCASE_NAME}_get_token_aux(const char *str, unsigned int len);
EOF
    fi
}

do_c() {
    if ! which gperf > /dev/null; then
        echo "gperf not found. You need to install gperf." > /dev/stderr;
        exit 1;
    fi;

    cat <<EOF | gperf --ignore-case -m16 -l -t -C -F",0" \
        --language=ANSI-C -N${LOWERCASE_NAME}_get_token_aux \
        | sed -e '/__gnu_inline__/d;s/\<\(__\|\)inline\>//g'
%{
`do_hdr`

#include <lib-common/core.h>
#include "${TARGET%.c}.h"

`do_function_decl`

%}
struct tok { const char *name; int val; };
%%
`do_tokens`
%%

enum ${LOWERCASE_NAME}_token
${LOWERCASE_NAME}_get_token(const char *s, int len)
{
    if (len < 0)
        len = strlen(s);

    if (len) {
        const struct tok *res = ${LOWERCASE_NAME}_get_token_aux(s, len);
        if (res)
            return res->val;
    }
    return ${UPPERCASE_NAME}_TK_unknown;
}

enum ${LOWERCASE_NAME}_token
${LOWERCASE_NAME}_get_token_ps(pstream_t ps)
{
    size_t len = ps_len(&ps);

    if (len) {
        const struct tok *res = ${LOWERCASE_NAME}_get_token_aux(ps.s, len);
        if (res)
            return res->val;
    }
    return ${UPPERCASE_NAME}_TK_unknown;
}
EOF
}

extract_tokens() {
    grep '^### ' "$1" | cut -d ' ' -f 2
}


if test $# -eq 2; then
    TOKENS_FILE="$1"
    TARGET="$2"

    UPPERCASE_NAME=`basename ${TOKENS_FILE} | sed -e 's/\(.*\).tokens$/\U\1/'`
    UPPERCASE_NAME=`basename ${TOKENS_FILE} | sed -e 's/\(.*\).tokens$/\1/' | tr a-z A-Z`
    LOWERCASE_NAME=`echo ${UPPERCASE_NAME} | tr A-Z a-z`
elif test $# -eq 3; then
    TOKENS_FILE="$1"
    TARGET="$3"
    UPPERCASE_NAME=`echo ${2} | tr a-z A-Z`
    LOWERCASE_NAME=`echo ${2} | tr A-Z a-z`
else
    die "incorect number of arguments"
fi

trap "rm -f ${TARGET}" 0

rm -f "${TARGET}"
case "${TARGET}" in
    *.h) cat "${TOKENS_FILE}" | do_h > "${TARGET}";;
    *.c) cat "${TOKENS_FILE}" | do_c > "${TARGET}";;
    *)  die "you must ask for the 'h' or 'c' generation";;
esac
chmod -w "${TARGET}"

trap - 0
exit 0
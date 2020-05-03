/***************************************************************************/
/*                                                                         */
/* Copyright 2020 INTERSEC SA                                              */
/*                                                                         */
/* Licensed under the Apache License, Version 2.0 (the "License");         */
/* you may not use this file except in compliance with the License.        */
/* You may obtain a copy of the License at                                 */
/*                                                                         */
/*     http://www.apache.org/licenses/LICENSE-2.0                          */
/*                                                                         */
/* Unless required by applicable law or agreed to in writing, software     */
/* distributed under the License is distributed on an "AS IS" BASIS,       */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*/
/* See the License for the specific language governing permissions and     */
/* limitations under the License.                                          */
/*                                                                         */
/***************************************************************************/

#define X(x) LE32_T(x)
const uint32_t crc32table[8][256] = {
    {
        X(0x00000000), X(0x77073096), X(0xEE0E612C), X(0x990951BA),
        X(0x076DC419), X(0x706AF48F), X(0xE963A535), X(0x9E6495A3),
        X(0x0EDB8832), X(0x79DCB8A4), X(0xE0D5E91E), X(0x97D2D988),
        X(0x09B64C2B), X(0x7EB17CBD), X(0xE7B82D07), X(0x90BF1D91),
        X(0x1DB71064), X(0x6AB020F2), X(0xF3B97148), X(0x84BE41DE),
        X(0x1ADAD47D), X(0x6DDDE4EB), X(0xF4D4B551), X(0x83D385C7),
        X(0x136C9856), X(0x646BA8C0), X(0xFD62F97A), X(0x8A65C9EC),
        X(0x14015C4F), X(0x63066CD9), X(0xFA0F3D63), X(0x8D080DF5),
        X(0x3B6E20C8), X(0x4C69105E), X(0xD56041E4), X(0xA2677172),
        X(0x3C03E4D1), X(0x4B04D447), X(0xD20D85FD), X(0xA50AB56B),
        X(0x35B5A8FA), X(0x42B2986C), X(0xDBBBC9D6), X(0xACBCF940),
        X(0x32D86CE3), X(0x45DF5C75), X(0xDCD60DCF), X(0xABD13D59),
        X(0x26D930AC), X(0x51DE003A), X(0xC8D75180), X(0xBFD06116),
        X(0x21B4F4B5), X(0x56B3C423), X(0xCFBA9599), X(0xB8BDA50F),
        X(0x2802B89E), X(0x5F058808), X(0xC60CD9B2), X(0xB10BE924),
        X(0x2F6F7C87), X(0x58684C11), X(0xC1611DAB), X(0xB6662D3D),
        X(0x76DC4190), X(0x01DB7106), X(0x98D220BC), X(0xEFD5102A),
        X(0x71B18589), X(0x06B6B51F), X(0x9FBFE4A5), X(0xE8B8D433),
        X(0x7807C9A2), X(0x0F00F934), X(0x9609A88E), X(0xE10E9818),
        X(0x7F6A0DBB), X(0x086D3D2D), X(0x91646C97), X(0xE6635C01),
        X(0x6B6B51F4), X(0x1C6C6162), X(0x856530D8), X(0xF262004E),
        X(0x6C0695ED), X(0x1B01A57B), X(0x8208F4C1), X(0xF50FC457),
        X(0x65B0D9C6), X(0x12B7E950), X(0x8BBEB8EA), X(0xFCB9887C),
        X(0x62DD1DDF), X(0x15DA2D49), X(0x8CD37CF3), X(0xFBD44C65),
        X(0x4DB26158), X(0x3AB551CE), X(0xA3BC0074), X(0xD4BB30E2),
        X(0x4ADFA541), X(0x3DD895D7), X(0xA4D1C46D), X(0xD3D6F4FB),
        X(0x4369E96A), X(0x346ED9FC), X(0xAD678846), X(0xDA60B8D0),
        X(0x44042D73), X(0x33031DE5), X(0xAA0A4C5F), X(0xDD0D7CC9),
        X(0x5005713C), X(0x270241AA), X(0xBE0B1010), X(0xC90C2086),
        X(0x5768B525), X(0x206F85B3), X(0xB966D409), X(0xCE61E49F),
        X(0x5EDEF90E), X(0x29D9C998), X(0xB0D09822), X(0xC7D7A8B4),
        X(0x59B33D17), X(0x2EB40D81), X(0xB7BD5C3B), X(0xC0BA6CAD),
        X(0xEDB88320), X(0x9ABFB3B6), X(0x03B6E20C), X(0x74B1D29A),
        X(0xEAD54739), X(0x9DD277AF), X(0x04DB2615), X(0x73DC1683),
        X(0xE3630B12), X(0x94643B84), X(0x0D6D6A3E), X(0x7A6A5AA8),
        X(0xE40ECF0B), X(0x9309FF9D), X(0x0A00AE27), X(0x7D079EB1),
        X(0xF00F9344), X(0x8708A3D2), X(0x1E01F268), X(0x6906C2FE),
        X(0xF762575D), X(0x806567CB), X(0x196C3671), X(0x6E6B06E7),
        X(0xFED41B76), X(0x89D32BE0), X(0x10DA7A5A), X(0x67DD4ACC),
        X(0xF9B9DF6F), X(0x8EBEEFF9), X(0x17B7BE43), X(0x60B08ED5),
        X(0xD6D6A3E8), X(0xA1D1937E), X(0x38D8C2C4), X(0x4FDFF252),
        X(0xD1BB67F1), X(0xA6BC5767), X(0x3FB506DD), X(0x48B2364B),
        X(0xD80D2BDA), X(0xAF0A1B4C), X(0x36034AF6), X(0x41047A60),
        X(0xDF60EFC3), X(0xA867DF55), X(0x316E8EEF), X(0x4669BE79),
        X(0xCB61B38C), X(0xBC66831A), X(0x256FD2A0), X(0x5268E236),
        X(0xCC0C7795), X(0xBB0B4703), X(0x220216B9), X(0x5505262F),
        X(0xC5BA3BBE), X(0xB2BD0B28), X(0x2BB45A92), X(0x5CB36A04),
        X(0xC2D7FFA7), X(0xB5D0CF31), X(0x2CD99E8B), X(0x5BDEAE1D),
        X(0x9B64C2B0), X(0xEC63F226), X(0x756AA39C), X(0x026D930A),
        X(0x9C0906A9), X(0xEB0E363F), X(0x72076785), X(0x05005713),
        X(0x95BF4A82), X(0xE2B87A14), X(0x7BB12BAE), X(0x0CB61B38),
        X(0x92D28E9B), X(0xE5D5BE0D), X(0x7CDCEFB7), X(0x0BDBDF21),
        X(0x86D3D2D4), X(0xF1D4E242), X(0x68DDB3F8), X(0x1FDA836E),
        X(0x81BE16CD), X(0xF6B9265B), X(0x6FB077E1), X(0x18B74777),
        X(0x88085AE6), X(0xFF0F6A70), X(0x66063BCA), X(0x11010B5C),
        X(0x8F659EFF), X(0xF862AE69), X(0x616BFFD3), X(0x166CCF45),
        X(0xA00AE278), X(0xD70DD2EE), X(0x4E048354), X(0x3903B3C2),
        X(0xA7672661), X(0xD06016F7), X(0x4969474D), X(0x3E6E77DB),
        X(0xAED16A4A), X(0xD9D65ADC), X(0x40DF0B66), X(0x37D83BF0),
        X(0xA9BCAE53), X(0xDEBB9EC5), X(0x47B2CF7F), X(0x30B5FFE9),
        X(0xBDBDF21C), X(0xCABAC28A), X(0x53B39330), X(0x24B4A3A6),
        X(0xBAD03605), X(0xCDD70693), X(0x54DE5729), X(0x23D967BF),
        X(0xB3667A2E), X(0xC4614AB8), X(0x5D681B02), X(0x2A6F2B94),
        X(0xB40BBE37), X(0xC30C8EA1), X(0x5A05DF1B), X(0x2D02EF8D),
    }, {
        X(0x00000000), X(0x191B3141), X(0x32366282), X(0x2B2D53C3),
        X(0x646CC504), X(0x7D77F445), X(0x565AA786), X(0x4F4196C7),
        X(0xC8D98A08), X(0xD1C2BB49), X(0xFAEFE88A), X(0xE3F4D9CB),
        X(0xACB54F0C), X(0xB5AE7E4D), X(0x9E832D8E), X(0x87981CCF),
        X(0x4AC21251), X(0x53D92310), X(0x78F470D3), X(0x61EF4192),
        X(0x2EAED755), X(0x37B5E614), X(0x1C98B5D7), X(0x05838496),
        X(0x821B9859), X(0x9B00A918), X(0xB02DFADB), X(0xA936CB9A),
        X(0xE6775D5D), X(0xFF6C6C1C), X(0xD4413FDF), X(0xCD5A0E9E),
        X(0x958424A2), X(0x8C9F15E3), X(0xA7B24620), X(0xBEA97761),
        X(0xF1E8E1A6), X(0xE8F3D0E7), X(0xC3DE8324), X(0xDAC5B265),
        X(0x5D5DAEAA), X(0x44469FEB), X(0x6F6BCC28), X(0x7670FD69),
        X(0x39316BAE), X(0x202A5AEF), X(0x0B07092C), X(0x121C386D),
        X(0xDF4636F3), X(0xC65D07B2), X(0xED705471), X(0xF46B6530),
        X(0xBB2AF3F7), X(0xA231C2B6), X(0x891C9175), X(0x9007A034),
        X(0x179FBCFB), X(0x0E848DBA), X(0x25A9DE79), X(0x3CB2EF38),
        X(0x73F379FF), X(0x6AE848BE), X(0x41C51B7D), X(0x58DE2A3C),
        X(0xF0794F05), X(0xE9627E44), X(0xC24F2D87), X(0xDB541CC6),
        X(0x94158A01), X(0x8D0EBB40), X(0xA623E883), X(0xBF38D9C2),
        X(0x38A0C50D), X(0x21BBF44C), X(0x0A96A78F), X(0x138D96CE),
        X(0x5CCC0009), X(0x45D73148), X(0x6EFA628B), X(0x77E153CA),
        X(0xBABB5D54), X(0xA3A06C15), X(0x888D3FD6), X(0x91960E97),
        X(0xDED79850), X(0xC7CCA911), X(0xECE1FAD2), X(0xF5FACB93),
        X(0x7262D75C), X(0x6B79E61D), X(0x4054B5DE), X(0x594F849F),
        X(0x160E1258), X(0x0F152319), X(0x243870DA), X(0x3D23419B),
        X(0x65FD6BA7), X(0x7CE65AE6), X(0x57CB0925), X(0x4ED03864),
        X(0x0191AEA3), X(0x188A9FE2), X(0x33A7CC21), X(0x2ABCFD60),
        X(0xAD24E1AF), X(0xB43FD0EE), X(0x9F12832D), X(0x8609B26C),
        X(0xC94824AB), X(0xD05315EA), X(0xFB7E4629), X(0xE2657768),
        X(0x2F3F79F6), X(0x362448B7), X(0x1D091B74), X(0x04122A35),
        X(0x4B53BCF2), X(0x52488DB3), X(0x7965DE70), X(0x607EEF31),
        X(0xE7E6F3FE), X(0xFEFDC2BF), X(0xD5D0917C), X(0xCCCBA03D),
        X(0x838A36FA), X(0x9A9107BB), X(0xB1BC5478), X(0xA8A76539),
        X(0x3B83984B), X(0x2298A90A), X(0x09B5FAC9), X(0x10AECB88),
        X(0x5FEF5D4F), X(0x46F46C0E), X(0x6DD93FCD), X(0x74C20E8C),
        X(0xF35A1243), X(0xEA412302), X(0xC16C70C1), X(0xD8774180),
        X(0x9736D747), X(0x8E2DE606), X(0xA500B5C5), X(0xBC1B8484),
        X(0x71418A1A), X(0x685ABB5B), X(0x4377E898), X(0x5A6CD9D9),
        X(0x152D4F1E), X(0x0C367E5F), X(0x271B2D9C), X(0x3E001CDD),
        X(0xB9980012), X(0xA0833153), X(0x8BAE6290), X(0x92B553D1),
        X(0xDDF4C516), X(0xC4EFF457), X(0xEFC2A794), X(0xF6D996D5),
        X(0xAE07BCE9), X(0xB71C8DA8), X(0x9C31DE6B), X(0x852AEF2A),
        X(0xCA6B79ED), X(0xD37048AC), X(0xF85D1B6F), X(0xE1462A2E),
        X(0x66DE36E1), X(0x7FC507A0), X(0x54E85463), X(0x4DF36522),
        X(0x02B2F3E5), X(0x1BA9C2A4), X(0x30849167), X(0x299FA026),
        X(0xE4C5AEB8), X(0xFDDE9FF9), X(0xD6F3CC3A), X(0xCFE8FD7B),
        X(0x80A96BBC), X(0x99B25AFD), X(0xB29F093E), X(0xAB84387F),
        X(0x2C1C24B0), X(0x350715F1), X(0x1E2A4632), X(0x07317773),
        X(0x4870E1B4), X(0x516BD0F5), X(0x7A468336), X(0x635DB277),
        X(0xCBFAD74E), X(0xD2E1E60F), X(0xF9CCB5CC), X(0xE0D7848D),
        X(0xAF96124A), X(0xB68D230B), X(0x9DA070C8), X(0x84BB4189),
        X(0x03235D46), X(0x1A386C07), X(0x31153FC4), X(0x280E0E85),
        X(0x674F9842), X(0x7E54A903), X(0x5579FAC0), X(0x4C62CB81),
        X(0x8138C51F), X(0x9823F45E), X(0xB30EA79D), X(0xAA1596DC),
        X(0xE554001B), X(0xFC4F315A), X(0xD7626299), X(0xCE7953D8),
        X(0x49E14F17), X(0x50FA7E56), X(0x7BD72D95), X(0x62CC1CD4),
        X(0x2D8D8A13), X(0x3496BB52), X(0x1FBBE891), X(0x06A0D9D0),
        X(0x5E7EF3EC), X(0x4765C2AD), X(0x6C48916E), X(0x7553A02F),
        X(0x3A1236E8), X(0x230907A9), X(0x0824546A), X(0x113F652B),
        X(0x96A779E4), X(0x8FBC48A5), X(0xA4911B66), X(0xBD8A2A27),
        X(0xF2CBBCE0), X(0xEBD08DA1), X(0xC0FDDE62), X(0xD9E6EF23),
        X(0x14BCE1BD), X(0x0DA7D0FC), X(0x268A833F), X(0x3F91B27E),
        X(0x70D024B9), X(0x69CB15F8), X(0x42E6463B), X(0x5BFD777A),
        X(0xDC656BB5), X(0xC57E5AF4), X(0xEE530937), X(0xF7483876),
        X(0xB809AEB1), X(0xA1129FF0), X(0x8A3FCC33), X(0x9324FD72),
    }, {
        X(0x00000000), X(0x01C26A37), X(0x0384D46E), X(0x0246BE59),
        X(0x0709A8DC), X(0x06CBC2EB), X(0x048D7CB2), X(0x054F1685),
        X(0x0E1351B8), X(0x0FD13B8F), X(0x0D9785D6), X(0x0C55EFE1),
        X(0x091AF964), X(0x08D89353), X(0x0A9E2D0A), X(0x0B5C473D),
        X(0x1C26A370), X(0x1DE4C947), X(0x1FA2771E), X(0x1E601D29),
        X(0x1B2F0BAC), X(0x1AED619B), X(0x18ABDFC2), X(0x1969B5F5),
        X(0x1235F2C8), X(0x13F798FF), X(0x11B126A6), X(0x10734C91),
        X(0x153C5A14), X(0x14FE3023), X(0x16B88E7A), X(0x177AE44D),
        X(0x384D46E0), X(0x398F2CD7), X(0x3BC9928E), X(0x3A0BF8B9),
        X(0x3F44EE3C), X(0x3E86840B), X(0x3CC03A52), X(0x3D025065),
        X(0x365E1758), X(0x379C7D6F), X(0x35DAC336), X(0x3418A901),
        X(0x3157BF84), X(0x3095D5B3), X(0x32D36BEA), X(0x331101DD),
        X(0x246BE590), X(0x25A98FA7), X(0x27EF31FE), X(0x262D5BC9),
        X(0x23624D4C), X(0x22A0277B), X(0x20E69922), X(0x2124F315),
        X(0x2A78B428), X(0x2BBADE1F), X(0x29FC6046), X(0x283E0A71),
        X(0x2D711CF4), X(0x2CB376C3), X(0x2EF5C89A), X(0x2F37A2AD),
        X(0x709A8DC0), X(0x7158E7F7), X(0x731E59AE), X(0x72DC3399),
        X(0x7793251C), X(0x76514F2B), X(0x7417F172), X(0x75D59B45),
        X(0x7E89DC78), X(0x7F4BB64F), X(0x7D0D0816), X(0x7CCF6221),
        X(0x798074A4), X(0x78421E93), X(0x7A04A0CA), X(0x7BC6CAFD),
        X(0x6CBC2EB0), X(0x6D7E4487), X(0x6F38FADE), X(0x6EFA90E9),
        X(0x6BB5866C), X(0x6A77EC5B), X(0x68315202), X(0x69F33835),
        X(0x62AF7F08), X(0x636D153F), X(0x612BAB66), X(0x60E9C151),
        X(0x65A6D7D4), X(0x6464BDE3), X(0x662203BA), X(0x67E0698D),
        X(0x48D7CB20), X(0x4915A117), X(0x4B531F4E), X(0x4A917579),
        X(0x4FDE63FC), X(0x4E1C09CB), X(0x4C5AB792), X(0x4D98DDA5),
        X(0x46C49A98), X(0x4706F0AF), X(0x45404EF6), X(0x448224C1),
        X(0x41CD3244), X(0x400F5873), X(0x4249E62A), X(0x438B8C1D),
        X(0x54F16850), X(0x55330267), X(0x5775BC3E), X(0x56B7D609),
        X(0x53F8C08C), X(0x523AAABB), X(0x507C14E2), X(0x51BE7ED5),
        X(0x5AE239E8), X(0x5B2053DF), X(0x5966ED86), X(0x58A487B1),
        X(0x5DEB9134), X(0x5C29FB03), X(0x5E6F455A), X(0x5FAD2F6D),
        X(0xE1351B80), X(0xE0F771B7), X(0xE2B1CFEE), X(0xE373A5D9),
        X(0xE63CB35C), X(0xE7FED96B), X(0xE5B86732), X(0xE47A0D05),
        X(0xEF264A38), X(0xEEE4200F), X(0xECA29E56), X(0xED60F461),
        X(0xE82FE2E4), X(0xE9ED88D3), X(0xEBAB368A), X(0xEA695CBD),
        X(0xFD13B8F0), X(0xFCD1D2C7), X(0xFE976C9E), X(0xFF5506A9),
        X(0xFA1A102C), X(0xFBD87A1B), X(0xF99EC442), X(0xF85CAE75),
        X(0xF300E948), X(0xF2C2837F), X(0xF0843D26), X(0xF1465711),
        X(0xF4094194), X(0xF5CB2BA3), X(0xF78D95FA), X(0xF64FFFCD),
        X(0xD9785D60), X(0xD8BA3757), X(0xDAFC890E), X(0xDB3EE339),
        X(0xDE71F5BC), X(0xDFB39F8B), X(0xDDF521D2), X(0xDC374BE5),
        X(0xD76B0CD8), X(0xD6A966EF), X(0xD4EFD8B6), X(0xD52DB281),
        X(0xD062A404), X(0xD1A0CE33), X(0xD3E6706A), X(0xD2241A5D),
        X(0xC55EFE10), X(0xC49C9427), X(0xC6DA2A7E), X(0xC7184049),
        X(0xC25756CC), X(0xC3953CFB), X(0xC1D382A2), X(0xC011E895),
        X(0xCB4DAFA8), X(0xCA8FC59F), X(0xC8C97BC6), X(0xC90B11F1),
        X(0xCC440774), X(0xCD866D43), X(0xCFC0D31A), X(0xCE02B92D),
        X(0x91AF9640), X(0x906DFC77), X(0x922B422E), X(0x93E92819),
        X(0x96A63E9C), X(0x976454AB), X(0x9522EAF2), X(0x94E080C5),
        X(0x9FBCC7F8), X(0x9E7EADCF), X(0x9C381396), X(0x9DFA79A1),
        X(0x98B56F24), X(0x99770513), X(0x9B31BB4A), X(0x9AF3D17D),
        X(0x8D893530), X(0x8C4B5F07), X(0x8E0DE15E), X(0x8FCF8B69),
        X(0x8A809DEC), X(0x8B42F7DB), X(0x89044982), X(0x88C623B5),
        X(0x839A6488), X(0x82580EBF), X(0x801EB0E6), X(0x81DCDAD1),
        X(0x8493CC54), X(0x8551A663), X(0x8717183A), X(0x86D5720D),
        X(0xA9E2D0A0), X(0xA820BA97), X(0xAA6604CE), X(0xABA46EF9),
        X(0xAEEB787C), X(0xAF29124B), X(0xAD6FAC12), X(0xACADC625),
        X(0xA7F18118), X(0xA633EB2F), X(0xA4755576), X(0xA5B73F41),
        X(0xA0F829C4), X(0xA13A43F3), X(0xA37CFDAA), X(0xA2BE979D),
        X(0xB5C473D0), X(0xB40619E7), X(0xB640A7BE), X(0xB782CD89),
        X(0xB2CDDB0C), X(0xB30FB13B), X(0xB1490F62), X(0xB08B6555),
        X(0xBBD72268), X(0xBA15485F), X(0xB853F606), X(0xB9919C31),
        X(0xBCDE8AB4), X(0xBD1CE083), X(0xBF5A5EDA), X(0xBE9834ED),
    }, {
        X(0x00000000), X(0xB8BC6765), X(0xAA09C88B), X(0x12B5AFEE),
        X(0x8F629757), X(0x37DEF032), X(0x256B5FDC), X(0x9DD738B9),
        X(0xC5B428EF), X(0x7D084F8A), X(0x6FBDE064), X(0xD7018701),
        X(0x4AD6BFB8), X(0xF26AD8DD), X(0xE0DF7733), X(0x58631056),
        X(0x5019579F), X(0xE8A530FA), X(0xFA109F14), X(0x42ACF871),
        X(0xDF7BC0C8), X(0x67C7A7AD), X(0x75720843), X(0xCDCE6F26),
        X(0x95AD7F70), X(0x2D111815), X(0x3FA4B7FB), X(0x8718D09E),
        X(0x1ACFE827), X(0xA2738F42), X(0xB0C620AC), X(0x087A47C9),
        X(0xA032AF3E), X(0x188EC85B), X(0x0A3B67B5), X(0xB28700D0),
        X(0x2F503869), X(0x97EC5F0C), X(0x8559F0E2), X(0x3DE59787),
        X(0x658687D1), X(0xDD3AE0B4), X(0xCF8F4F5A), X(0x7733283F),
        X(0xEAE41086), X(0x525877E3), X(0x40EDD80D), X(0xF851BF68),
        X(0xF02BF8A1), X(0x48979FC4), X(0x5A22302A), X(0xE29E574F),
        X(0x7F496FF6), X(0xC7F50893), X(0xD540A77D), X(0x6DFCC018),
        X(0x359FD04E), X(0x8D23B72B), X(0x9F9618C5), X(0x272A7FA0),
        X(0xBAFD4719), X(0x0241207C), X(0x10F48F92), X(0xA848E8F7),
        X(0x9B14583D), X(0x23A83F58), X(0x311D90B6), X(0x89A1F7D3),
        X(0x1476CF6A), X(0xACCAA80F), X(0xBE7F07E1), X(0x06C36084),
        X(0x5EA070D2), X(0xE61C17B7), X(0xF4A9B859), X(0x4C15DF3C),
        X(0xD1C2E785), X(0x697E80E0), X(0x7BCB2F0E), X(0xC377486B),
        X(0xCB0D0FA2), X(0x73B168C7), X(0x6104C729), X(0xD9B8A04C),
        X(0x446F98F5), X(0xFCD3FF90), X(0xEE66507E), X(0x56DA371B),
        X(0x0EB9274D), X(0xB6054028), X(0xA4B0EFC6), X(0x1C0C88A3),
        X(0x81DBB01A), X(0x3967D77F), X(0x2BD27891), X(0x936E1FF4),
        X(0x3B26F703), X(0x839A9066), X(0x912F3F88), X(0x299358ED),
        X(0xB4446054), X(0x0CF80731), X(0x1E4DA8DF), X(0xA6F1CFBA),
        X(0xFE92DFEC), X(0x462EB889), X(0x549B1767), X(0xEC277002),
        X(0x71F048BB), X(0xC94C2FDE), X(0xDBF98030), X(0x6345E755),
        X(0x6B3FA09C), X(0xD383C7F9), X(0xC1366817), X(0x798A0F72),
        X(0xE45D37CB), X(0x5CE150AE), X(0x4E54FF40), X(0xF6E89825),
        X(0xAE8B8873), X(0x1637EF16), X(0x048240F8), X(0xBC3E279D),
        X(0x21E91F24), X(0x99557841), X(0x8BE0D7AF), X(0x335CB0CA),
        X(0xED59B63B), X(0x55E5D15E), X(0x47507EB0), X(0xFFEC19D5),
        X(0x623B216C), X(0xDA874609), X(0xC832E9E7), X(0x708E8E82),
        X(0x28ED9ED4), X(0x9051F9B1), X(0x82E4565F), X(0x3A58313A),
        X(0xA78F0983), X(0x1F336EE6), X(0x0D86C108), X(0xB53AA66D),
        X(0xBD40E1A4), X(0x05FC86C1), X(0x1749292F), X(0xAFF54E4A),
        X(0x322276F3), X(0x8A9E1196), X(0x982BBE78), X(0x2097D91D),
        X(0x78F4C94B), X(0xC048AE2E), X(0xD2FD01C0), X(0x6A4166A5),
        X(0xF7965E1C), X(0x4F2A3979), X(0x5D9F9697), X(0xE523F1F2),
        X(0x4D6B1905), X(0xF5D77E60), X(0xE762D18E), X(0x5FDEB6EB),
        X(0xC2098E52), X(0x7AB5E937), X(0x680046D9), X(0xD0BC21BC),
        X(0x88DF31EA), X(0x3063568F), X(0x22D6F961), X(0x9A6A9E04),
        X(0x07BDA6BD), X(0xBF01C1D8), X(0xADB46E36), X(0x15080953),
        X(0x1D724E9A), X(0xA5CE29FF), X(0xB77B8611), X(0x0FC7E174),
        X(0x9210D9CD), X(0x2AACBEA8), X(0x38191146), X(0x80A57623),
        X(0xD8C66675), X(0x607A0110), X(0x72CFAEFE), X(0xCA73C99B),
        X(0x57A4F122), X(0xEF189647), X(0xFDAD39A9), X(0x45115ECC),
        X(0x764DEE06), X(0xCEF18963), X(0xDC44268D), X(0x64F841E8),
        X(0xF92F7951), X(0x41931E34), X(0x5326B1DA), X(0xEB9AD6BF),
        X(0xB3F9C6E9), X(0x0B45A18C), X(0x19F00E62), X(0xA14C6907),
        X(0x3C9B51BE), X(0x842736DB), X(0x96929935), X(0x2E2EFE50),
        X(0x2654B999), X(0x9EE8DEFC), X(0x8C5D7112), X(0x34E11677),
        X(0xA9362ECE), X(0x118A49AB), X(0x033FE645), X(0xBB838120),
        X(0xE3E09176), X(0x5B5CF613), X(0x49E959FD), X(0xF1553E98),
        X(0x6C820621), X(0xD43E6144), X(0xC68BCEAA), X(0x7E37A9CF),
        X(0xD67F4138), X(0x6EC3265D), X(0x7C7689B3), X(0xC4CAEED6),
        X(0x591DD66F), X(0xE1A1B10A), X(0xF3141EE4), X(0x4BA87981),
        X(0x13CB69D7), X(0xAB770EB2), X(0xB9C2A15C), X(0x017EC639),
        X(0x9CA9FE80), X(0x241599E5), X(0x36A0360B), X(0x8E1C516E),
        X(0x866616A7), X(0x3EDA71C2), X(0x2C6FDE2C), X(0x94D3B949),
        X(0x090481F0), X(0xB1B8E695), X(0xA30D497B), X(0x1BB12E1E),
        X(0x43D23E48), X(0xFB6E592D), X(0xE9DBF6C3), X(0x516791A6),
        X(0xCCB0A91F), X(0x740CCE7A), X(0x66B96194), X(0xDE0506F1),
    }, {
        X(0x00000000), X(0x3D6029B0), X(0x7AC05360), X(0x47A07AD0),
        X(0xF580A6C0), X(0xC8E08F70), X(0x8F40F5A0), X(0xB220DC10),
        X(0x30704BC1), X(0x0D106271), X(0x4AB018A1), X(0x77D03111),
        X(0xC5F0ED01), X(0xF890C4B1), X(0xBF30BE61), X(0x825097D1),
        X(0x60E09782), X(0x5D80BE32), X(0x1A20C4E2), X(0x2740ED52),
        X(0x95603142), X(0xA80018F2), X(0xEFA06222), X(0xD2C04B92),
        X(0x5090DC43), X(0x6DF0F5F3), X(0x2A508F23), X(0x1730A693),
        X(0xA5107A83), X(0x98705333), X(0xDFD029E3), X(0xE2B00053),
        X(0xC1C12F04), X(0xFCA106B4), X(0xBB017C64), X(0x866155D4),
        X(0x344189C4), X(0x0921A074), X(0x4E81DAA4), X(0x73E1F314),
        X(0xF1B164C5), X(0xCCD14D75), X(0x8B7137A5), X(0xB6111E15),
        X(0x0431C205), X(0x3951EBB5), X(0x7EF19165), X(0x4391B8D5),
        X(0xA121B886), X(0x9C419136), X(0xDBE1EBE6), X(0xE681C256),
        X(0x54A11E46), X(0x69C137F6), X(0x2E614D26), X(0x13016496),
        X(0x9151F347), X(0xAC31DAF7), X(0xEB91A027), X(0xD6F18997),
        X(0x64D15587), X(0x59B17C37), X(0x1E1106E7), X(0x23712F57),
        X(0x58F35849), X(0x659371F9), X(0x22330B29), X(0x1F532299),
        X(0xAD73FE89), X(0x9013D739), X(0xD7B3ADE9), X(0xEAD38459),
        X(0x68831388), X(0x55E33A38), X(0x124340E8), X(0x2F236958),
        X(0x9D03B548), X(0xA0639CF8), X(0xE7C3E628), X(0xDAA3CF98),
        X(0x3813CFCB), X(0x0573E67B), X(0x42D39CAB), X(0x7FB3B51B),
        X(0xCD93690B), X(0xF0F340BB), X(0xB7533A6B), X(0x8A3313DB),
        X(0x0863840A), X(0x3503ADBA), X(0x72A3D76A), X(0x4FC3FEDA),
        X(0xFDE322CA), X(0xC0830B7A), X(0x872371AA), X(0xBA43581A),
        X(0x9932774D), X(0xA4525EFD), X(0xE3F2242D), X(0xDE920D9D),
        X(0x6CB2D18D), X(0x51D2F83D), X(0x167282ED), X(0x2B12AB5D),
        X(0xA9423C8C), X(0x9422153C), X(0xD3826FEC), X(0xEEE2465C),
        X(0x5CC29A4C), X(0x61A2B3FC), X(0x2602C92C), X(0x1B62E09C),
        X(0xF9D2E0CF), X(0xC4B2C97F), X(0x8312B3AF), X(0xBE729A1F),
        X(0x0C52460F), X(0x31326FBF), X(0x7692156F), X(0x4BF23CDF),
        X(0xC9A2AB0E), X(0xF4C282BE), X(0xB362F86E), X(0x8E02D1DE),
        X(0x3C220DCE), X(0x0142247E), X(0x46E25EAE), X(0x7B82771E),
        X(0xB1E6B092), X(0x8C869922), X(0xCB26E3F2), X(0xF646CA42),
        X(0x44661652), X(0x79063FE2), X(0x3EA64532), X(0x03C66C82),
        X(0x8196FB53), X(0xBCF6D2E3), X(0xFB56A833), X(0xC6368183),
        X(0x74165D93), X(0x49767423), X(0x0ED60EF3), X(0x33B62743),
        X(0xD1062710), X(0xEC660EA0), X(0xABC67470), X(0x96A65DC0),
        X(0x248681D0), X(0x19E6A860), X(0x5E46D2B0), X(0x6326FB00),
        X(0xE1766CD1), X(0xDC164561), X(0x9BB63FB1), X(0xA6D61601),
        X(0x14F6CA11), X(0x2996E3A1), X(0x6E369971), X(0x5356B0C1),
        X(0x70279F96), X(0x4D47B626), X(0x0AE7CCF6), X(0x3787E546),
        X(0x85A73956), X(0xB8C710E6), X(0xFF676A36), X(0xC2074386),
        X(0x4057D457), X(0x7D37FDE7), X(0x3A978737), X(0x07F7AE87),
        X(0xB5D77297), X(0x88B75B27), X(0xCF1721F7), X(0xF2770847),
        X(0x10C70814), X(0x2DA721A4), X(0x6A075B74), X(0x576772C4),
        X(0xE547AED4), X(0xD8278764), X(0x9F87FDB4), X(0xA2E7D404),
        X(0x20B743D5), X(0x1DD76A65), X(0x5A7710B5), X(0x67173905),
        X(0xD537E515), X(0xE857CCA5), X(0xAFF7B675), X(0x92979FC5),
        X(0xE915E8DB), X(0xD475C16B), X(0x93D5BBBB), X(0xAEB5920B),
        X(0x1C954E1B), X(0x21F567AB), X(0x66551D7B), X(0x5B3534CB),
        X(0xD965A31A), X(0xE4058AAA), X(0xA3A5F07A), X(0x9EC5D9CA),
        X(0x2CE505DA), X(0x11852C6A), X(0x562556BA), X(0x6B457F0A),
        X(0x89F57F59), X(0xB49556E9), X(0xF3352C39), X(0xCE550589),
        X(0x7C75D999), X(0x4115F029), X(0x06B58AF9), X(0x3BD5A349),
        X(0xB9853498), X(0x84E51D28), X(0xC34567F8), X(0xFE254E48),
        X(0x4C059258), X(0x7165BBE8), X(0x36C5C138), X(0x0BA5E888),
        X(0x28D4C7DF), X(0x15B4EE6F), X(0x521494BF), X(0x6F74BD0F),
        X(0xDD54611F), X(0xE03448AF), X(0xA794327F), X(0x9AF41BCF),
        X(0x18A48C1E), X(0x25C4A5AE), X(0x6264DF7E), X(0x5F04F6CE),
        X(0xED242ADE), X(0xD044036E), X(0x97E479BE), X(0xAA84500E),
        X(0x4834505D), X(0x755479ED), X(0x32F4033D), X(0x0F942A8D),
        X(0xBDB4F69D), X(0x80D4DF2D), X(0xC774A5FD), X(0xFA148C4D),
        X(0x78441B9C), X(0x4524322C), X(0x028448FC), X(0x3FE4614C),
        X(0x8DC4BD5C), X(0xB0A494EC), X(0xF704EE3C), X(0xCA64C78C),
    }, {
        X(0x00000000), X(0xCB5CD3A5), X(0x4DC8A10B), X(0x869472AE),
        X(0x9B914216), X(0x50CD91B3), X(0xD659E31D), X(0x1D0530B8),
        X(0xEC53826D), X(0x270F51C8), X(0xA19B2366), X(0x6AC7F0C3),
        X(0x77C2C07B), X(0xBC9E13DE), X(0x3A0A6170), X(0xF156B2D5),
        X(0x03D6029B), X(0xC88AD13E), X(0x4E1EA390), X(0x85427035),
        X(0x9847408D), X(0x531B9328), X(0xD58FE186), X(0x1ED33223),
        X(0xEF8580F6), X(0x24D95353), X(0xA24D21FD), X(0x6911F258),
        X(0x7414C2E0), X(0xBF481145), X(0x39DC63EB), X(0xF280B04E),
        X(0x07AC0536), X(0xCCF0D693), X(0x4A64A43D), X(0x81387798),
        X(0x9C3D4720), X(0x57619485), X(0xD1F5E62B), X(0x1AA9358E),
        X(0xEBFF875B), X(0x20A354FE), X(0xA6372650), X(0x6D6BF5F5),
        X(0x706EC54D), X(0xBB3216E8), X(0x3DA66446), X(0xF6FAB7E3),
        X(0x047A07AD), X(0xCF26D408), X(0x49B2A6A6), X(0x82EE7503),
        X(0x9FEB45BB), X(0x54B7961E), X(0xD223E4B0), X(0x197F3715),
        X(0xE82985C0), X(0x23755665), X(0xA5E124CB), X(0x6EBDF76E),
        X(0x73B8C7D6), X(0xB8E41473), X(0x3E7066DD), X(0xF52CB578),
        X(0x0F580A6C), X(0xC404D9C9), X(0x4290AB67), X(0x89CC78C2),
        X(0x94C9487A), X(0x5F959BDF), X(0xD901E971), X(0x125D3AD4),
        X(0xE30B8801), X(0x28575BA4), X(0xAEC3290A), X(0x659FFAAF),
        X(0x789ACA17), X(0xB3C619B2), X(0x35526B1C), X(0xFE0EB8B9),
        X(0x0C8E08F7), X(0xC7D2DB52), X(0x4146A9FC), X(0x8A1A7A59),
        X(0x971F4AE1), X(0x5C439944), X(0xDAD7EBEA), X(0x118B384F),
        X(0xE0DD8A9A), X(0x2B81593F), X(0xAD152B91), X(0x6649F834),
        X(0x7B4CC88C), X(0xB0101B29), X(0x36846987), X(0xFDD8BA22),
        X(0x08F40F5A), X(0xC3A8DCFF), X(0x453CAE51), X(0x8E607DF4),
        X(0x93654D4C), X(0x58399EE9), X(0xDEADEC47), X(0x15F13FE2),
        X(0xE4A78D37), X(0x2FFB5E92), X(0xA96F2C3C), X(0x6233FF99),
        X(0x7F36CF21), X(0xB46A1C84), X(0x32FE6E2A), X(0xF9A2BD8F),
        X(0x0B220DC1), X(0xC07EDE64), X(0x46EAACCA), X(0x8DB67F6F),
        X(0x90B34FD7), X(0x5BEF9C72), X(0xDD7BEEDC), X(0x16273D79),
        X(0xE7718FAC), X(0x2C2D5C09), X(0xAAB92EA7), X(0x61E5FD02),
        X(0x7CE0CDBA), X(0xB7BC1E1F), X(0x31286CB1), X(0xFA74BF14),
        X(0x1EB014D8), X(0xD5ECC77D), X(0x5378B5D3), X(0x98246676),
        X(0x852156CE), X(0x4E7D856B), X(0xC8E9F7C5), X(0x03B52460),
        X(0xF2E396B5), X(0x39BF4510), X(0xBF2B37BE), X(0x7477E41B),
        X(0x6972D4A3), X(0xA22E0706), X(0x24BA75A8), X(0xEFE6A60D),
        X(0x1D661643), X(0xD63AC5E6), X(0x50AEB748), X(0x9BF264ED),
        X(0x86F75455), X(0x4DAB87F0), X(0xCB3FF55E), X(0x006326FB),
        X(0xF135942E), X(0x3A69478B), X(0xBCFD3525), X(0x77A1E680),
        X(0x6AA4D638), X(0xA1F8059D), X(0x276C7733), X(0xEC30A496),
        X(0x191C11EE), X(0xD240C24B), X(0x54D4B0E5), X(0x9F886340),
        X(0x828D53F8), X(0x49D1805D), X(0xCF45F2F3), X(0x04192156),
        X(0xF54F9383), X(0x3E134026), X(0xB8873288), X(0x73DBE12D),
        X(0x6EDED195), X(0xA5820230), X(0x2316709E), X(0xE84AA33B),
        X(0x1ACA1375), X(0xD196C0D0), X(0x5702B27E), X(0x9C5E61DB),
        X(0x815B5163), X(0x4A0782C6), X(0xCC93F068), X(0x07CF23CD),
        X(0xF6999118), X(0x3DC542BD), X(0xBB513013), X(0x700DE3B6),
        X(0x6D08D30E), X(0xA65400AB), X(0x20C07205), X(0xEB9CA1A0),
        X(0x11E81EB4), X(0xDAB4CD11), X(0x5C20BFBF), X(0x977C6C1A),
        X(0x8A795CA2), X(0x41258F07), X(0xC7B1FDA9), X(0x0CED2E0C),
        X(0xFDBB9CD9), X(0x36E74F7C), X(0xB0733DD2), X(0x7B2FEE77),
        X(0x662ADECF), X(0xAD760D6A), X(0x2BE27FC4), X(0xE0BEAC61),
        X(0x123E1C2F), X(0xD962CF8A), X(0x5FF6BD24), X(0x94AA6E81),
        X(0x89AF5E39), X(0x42F38D9C), X(0xC467FF32), X(0x0F3B2C97),
        X(0xFE6D9E42), X(0x35314DE7), X(0xB3A53F49), X(0x78F9ECEC),
        X(0x65FCDC54), X(0xAEA00FF1), X(0x28347D5F), X(0xE368AEFA),
        X(0x16441B82), X(0xDD18C827), X(0x5B8CBA89), X(0x90D0692C),
        X(0x8DD55994), X(0x46898A31), X(0xC01DF89F), X(0x0B412B3A),
        X(0xFA1799EF), X(0x314B4A4A), X(0xB7DF38E4), X(0x7C83EB41),
        X(0x6186DBF9), X(0xAADA085C), X(0x2C4E7AF2), X(0xE712A957),
        X(0x15921919), X(0xDECECABC), X(0x585AB812), X(0x93066BB7),
        X(0x8E035B0F), X(0x455F88AA), X(0xC3CBFA04), X(0x089729A1),
        X(0xF9C19B74), X(0x329D48D1), X(0xB4093A7F), X(0x7F55E9DA),
        X(0x6250D962), X(0xA90C0AC7), X(0x2F987869), X(0xE4C4ABCC),
    }, {
        X(0x00000000), X(0xA6770BB4), X(0x979F1129), X(0x31E81A9D),
        X(0xF44F2413), X(0x52382FA7), X(0x63D0353A), X(0xC5A73E8E),
        X(0x33EF4E67), X(0x959845D3), X(0xA4705F4E), X(0x020754FA),
        X(0xC7A06A74), X(0x61D761C0), X(0x503F7B5D), X(0xF64870E9),
        X(0x67DE9CCE), X(0xC1A9977A), X(0xF0418DE7), X(0x56368653),
        X(0x9391B8DD), X(0x35E6B369), X(0x040EA9F4), X(0xA279A240),
        X(0x5431D2A9), X(0xF246D91D), X(0xC3AEC380), X(0x65D9C834),
        X(0xA07EF6BA), X(0x0609FD0E), X(0x37E1E793), X(0x9196EC27),
        X(0xCFBD399C), X(0x69CA3228), X(0x582228B5), X(0xFE552301),
        X(0x3BF21D8F), X(0x9D85163B), X(0xAC6D0CA6), X(0x0A1A0712),
        X(0xFC5277FB), X(0x5A257C4F), X(0x6BCD66D2), X(0xCDBA6D66),
        X(0x081D53E8), X(0xAE6A585C), X(0x9F8242C1), X(0x39F54975),
        X(0xA863A552), X(0x0E14AEE6), X(0x3FFCB47B), X(0x998BBFCF),
        X(0x5C2C8141), X(0xFA5B8AF5), X(0xCBB39068), X(0x6DC49BDC),
        X(0x9B8CEB35), X(0x3DFBE081), X(0x0C13FA1C), X(0xAA64F1A8),
        X(0x6FC3CF26), X(0xC9B4C492), X(0xF85CDE0F), X(0x5E2BD5BB),
        X(0x440B7579), X(0xE27C7ECD), X(0xD3946450), X(0x75E36FE4),
        X(0xB044516A), X(0x16335ADE), X(0x27DB4043), X(0x81AC4BF7),
        X(0x77E43B1E), X(0xD19330AA), X(0xE07B2A37), X(0x460C2183),
        X(0x83AB1F0D), X(0x25DC14B9), X(0x14340E24), X(0xB2430590),
        X(0x23D5E9B7), X(0x85A2E203), X(0xB44AF89E), X(0x123DF32A),
        X(0xD79ACDA4), X(0x71EDC610), X(0x4005DC8D), X(0xE672D739),
        X(0x103AA7D0), X(0xB64DAC64), X(0x87A5B6F9), X(0x21D2BD4D),
        X(0xE47583C3), X(0x42028877), X(0x73EA92EA), X(0xD59D995E),
        X(0x8BB64CE5), X(0x2DC14751), X(0x1C295DCC), X(0xBA5E5678),
        X(0x7FF968F6), X(0xD98E6342), X(0xE86679DF), X(0x4E11726B),
        X(0xB8590282), X(0x1E2E0936), X(0x2FC613AB), X(0x89B1181F),
        X(0x4C162691), X(0xEA612D25), X(0xDB8937B8), X(0x7DFE3C0C),
        X(0xEC68D02B), X(0x4A1FDB9F), X(0x7BF7C102), X(0xDD80CAB6),
        X(0x1827F438), X(0xBE50FF8C), X(0x8FB8E511), X(0x29CFEEA5),
        X(0xDF879E4C), X(0x79F095F8), X(0x48188F65), X(0xEE6F84D1),
        X(0x2BC8BA5F), X(0x8DBFB1EB), X(0xBC57AB76), X(0x1A20A0C2),
        X(0x8816EAF2), X(0x2E61E146), X(0x1F89FBDB), X(0xB9FEF06F),
        X(0x7C59CEE1), X(0xDA2EC555), X(0xEBC6DFC8), X(0x4DB1D47C),
        X(0xBBF9A495), X(0x1D8EAF21), X(0x2C66B5BC), X(0x8A11BE08),
        X(0x4FB68086), X(0xE9C18B32), X(0xD82991AF), X(0x7E5E9A1B),
        X(0xEFC8763C), X(0x49BF7D88), X(0x78576715), X(0xDE206CA1),
        X(0x1B87522F), X(0xBDF0599B), X(0x8C184306), X(0x2A6F48B2),
        X(0xDC27385B), X(0x7A5033EF), X(0x4BB82972), X(0xEDCF22C6),
        X(0x28681C48), X(0x8E1F17FC), X(0xBFF70D61), X(0x198006D5),
        X(0x47ABD36E), X(0xE1DCD8DA), X(0xD034C247), X(0x7643C9F3),
        X(0xB3E4F77D), X(0x1593FCC9), X(0x247BE654), X(0x820CEDE0),
        X(0x74449D09), X(0xD23396BD), X(0xE3DB8C20), X(0x45AC8794),
        X(0x800BB91A), X(0x267CB2AE), X(0x1794A833), X(0xB1E3A387),
        X(0x20754FA0), X(0x86024414), X(0xB7EA5E89), X(0x119D553D),
        X(0xD43A6BB3), X(0x724D6007), X(0x43A57A9A), X(0xE5D2712E),
        X(0x139A01C7), X(0xB5ED0A73), X(0x840510EE), X(0x22721B5A),
        X(0xE7D525D4), X(0x41A22E60), X(0x704A34FD), X(0xD63D3F49),
        X(0xCC1D9F8B), X(0x6A6A943F), X(0x5B828EA2), X(0xFDF58516),
        X(0x3852BB98), X(0x9E25B02C), X(0xAFCDAAB1), X(0x09BAA105),
        X(0xFFF2D1EC), X(0x5985DA58), X(0x686DC0C5), X(0xCE1ACB71),
        X(0x0BBDF5FF), X(0xADCAFE4B), X(0x9C22E4D6), X(0x3A55EF62),
        X(0xABC30345), X(0x0DB408F1), X(0x3C5C126C), X(0x9A2B19D8),
        X(0x5F8C2756), X(0xF9FB2CE2), X(0xC813367F), X(0x6E643DCB),
        X(0x982C4D22), X(0x3E5B4696), X(0x0FB35C0B), X(0xA9C457BF),
        X(0x6C636931), X(0xCA146285), X(0xFBFC7818), X(0x5D8B73AC),
        X(0x03A0A617), X(0xA5D7ADA3), X(0x943FB73E), X(0x3248BC8A),
        X(0xF7EF8204), X(0x519889B0), X(0x6070932D), X(0xC6079899),
        X(0x304FE870), X(0x9638E3C4), X(0xA7D0F959), X(0x01A7F2ED),
        X(0xC400CC63), X(0x6277C7D7), X(0x539FDD4A), X(0xF5E8D6FE),
        X(0x647E3AD9), X(0xC209316D), X(0xF3E12BF0), X(0x55962044),
        X(0x90311ECA), X(0x3646157E), X(0x07AE0FE3), X(0xA1D90457),
        X(0x579174BE), X(0xF1E67F0A), X(0xC00E6597), X(0x66796E23),
        X(0xA3DE50AD), X(0x05A95B19), X(0x34414184), X(0x92364A30),
    }, {
        X(0x00000000), X(0xCCAA009E), X(0x4225077D), X(0x8E8F07E3),
        X(0x844A0EFA), X(0x48E00E64), X(0xC66F0987), X(0x0AC50919),
        X(0xD3E51BB5), X(0x1F4F1B2B), X(0x91C01CC8), X(0x5D6A1C56),
        X(0x57AF154F), X(0x9B0515D1), X(0x158A1232), X(0xD92012AC),
        X(0x7CBB312B), X(0xB01131B5), X(0x3E9E3656), X(0xF23436C8),
        X(0xF8F13FD1), X(0x345B3F4F), X(0xBAD438AC), X(0x767E3832),
        X(0xAF5E2A9E), X(0x63F42A00), X(0xED7B2DE3), X(0x21D12D7D),
        X(0x2B142464), X(0xE7BE24FA), X(0x69312319), X(0xA59B2387),
        X(0xF9766256), X(0x35DC62C8), X(0xBB53652B), X(0x77F965B5),
        X(0x7D3C6CAC), X(0xB1966C32), X(0x3F196BD1), X(0xF3B36B4F),
        X(0x2A9379E3), X(0xE639797D), X(0x68B67E9E), X(0xA41C7E00),
        X(0xAED97719), X(0x62737787), X(0xECFC7064), X(0x205670FA),
        X(0x85CD537D), X(0x496753E3), X(0xC7E85400), X(0x0B42549E),
        X(0x01875D87), X(0xCD2D5D19), X(0x43A25AFA), X(0x8F085A64),
        X(0x562848C8), X(0x9A824856), X(0x140D4FB5), X(0xD8A74F2B),
        X(0xD2624632), X(0x1EC846AC), X(0x9047414F), X(0x5CED41D1),
        X(0x299DC2ED), X(0xE537C273), X(0x6BB8C590), X(0xA712C50E),
        X(0xADD7CC17), X(0x617DCC89), X(0xEFF2CB6A), X(0x2358CBF4),
        X(0xFA78D958), X(0x36D2D9C6), X(0xB85DDE25), X(0x74F7DEBB),
        X(0x7E32D7A2), X(0xB298D73C), X(0x3C17D0DF), X(0xF0BDD041),
        X(0x5526F3C6), X(0x998CF358), X(0x1703F4BB), X(0xDBA9F425),
        X(0xD16CFD3C), X(0x1DC6FDA2), X(0x9349FA41), X(0x5FE3FADF),
        X(0x86C3E873), X(0x4A69E8ED), X(0xC4E6EF0E), X(0x084CEF90),
        X(0x0289E689), X(0xCE23E617), X(0x40ACE1F4), X(0x8C06E16A),
        X(0xD0EBA0BB), X(0x1C41A025), X(0x92CEA7C6), X(0x5E64A758),
        X(0x54A1AE41), X(0x980BAEDF), X(0x1684A93C), X(0xDA2EA9A2),
        X(0x030EBB0E), X(0xCFA4BB90), X(0x412BBC73), X(0x8D81BCED),
        X(0x8744B5F4), X(0x4BEEB56A), X(0xC561B289), X(0x09CBB217),
        X(0xAC509190), X(0x60FA910E), X(0xEE7596ED), X(0x22DF9673),
        X(0x281A9F6A), X(0xE4B09FF4), X(0x6A3F9817), X(0xA6959889),
        X(0x7FB58A25), X(0xB31F8ABB), X(0x3D908D58), X(0xF13A8DC6),
        X(0xFBFF84DF), X(0x37558441), X(0xB9DA83A2), X(0x7570833C),
        X(0x533B85DA), X(0x9F918544), X(0x111E82A7), X(0xDDB48239),
        X(0xD7718B20), X(0x1BDB8BBE), X(0x95548C5D), X(0x59FE8CC3),
        X(0x80DE9E6F), X(0x4C749EF1), X(0xC2FB9912), X(0x0E51998C),
        X(0x04949095), X(0xC83E900B), X(0x46B197E8), X(0x8A1B9776),
        X(0x2F80B4F1), X(0xE32AB46F), X(0x6DA5B38C), X(0xA10FB312),
        X(0xABCABA0B), X(0x6760BA95), X(0xE9EFBD76), X(0x2545BDE8),
        X(0xFC65AF44), X(0x30CFAFDA), X(0xBE40A839), X(0x72EAA8A7),
        X(0x782FA1BE), X(0xB485A120), X(0x3A0AA6C3), X(0xF6A0A65D),
        X(0xAA4DE78C), X(0x66E7E712), X(0xE868E0F1), X(0x24C2E06F),
        X(0x2E07E976), X(0xE2ADE9E8), X(0x6C22EE0B), X(0xA088EE95),
        X(0x79A8FC39), X(0xB502FCA7), X(0x3B8DFB44), X(0xF727FBDA),
        X(0xFDE2F2C3), X(0x3148F25D), X(0xBFC7F5BE), X(0x736DF520),
        X(0xD6F6D6A7), X(0x1A5CD639), X(0x94D3D1DA), X(0x5879D144),
        X(0x52BCD85D), X(0x9E16D8C3), X(0x1099DF20), X(0xDC33DFBE),
        X(0x0513CD12), X(0xC9B9CD8C), X(0x4736CA6F), X(0x8B9CCAF1),
        X(0x8159C3E8), X(0x4DF3C376), X(0xC37CC495), X(0x0FD6C40B),
        X(0x7AA64737), X(0xB60C47A9), X(0x3883404A), X(0xF42940D4),
        X(0xFEEC49CD), X(0x32464953), X(0xBCC94EB0), X(0x70634E2E),
        X(0xA9435C82), X(0x65E95C1C), X(0xEB665BFF), X(0x27CC5B61),
        X(0x2D095278), X(0xE1A352E6), X(0x6F2C5505), X(0xA386559B),
        X(0x061D761C), X(0xCAB77682), X(0x44387161), X(0x889271FF),
        X(0x825778E6), X(0x4EFD7878), X(0xC0727F9B), X(0x0CD87F05),
        X(0xD5F86DA9), X(0x19526D37), X(0x97DD6AD4), X(0x5B776A4A),
        X(0x51B26353), X(0x9D1863CD), X(0x1397642E), X(0xDF3D64B0),
        X(0x83D02561), X(0x4F7A25FF), X(0xC1F5221C), X(0x0D5F2282),
        X(0x079A2B9B), X(0xCB302B05), X(0x45BF2CE6), X(0x89152C78),
        X(0x50353ED4), X(0x9C9F3E4A), X(0x121039A9), X(0xDEBA3937),
        X(0xD47F302E), X(0x18D530B0), X(0x965A3753), X(0x5AF037CD),
        X(0xFF6B144A), X(0x33C114D4), X(0xBD4E1337), X(0x71E413A9),
        X(0x7B211AB0), X(0xB78B1A2E), X(0x39041DCD), X(0xF5AE1D53),
        X(0x2C8E0FFF), X(0xE0240F61), X(0x6EAB0882), X(0xA201081C),
        X(0xA8C40105), X(0x646E019B), X(0xEAE10678), X(0x264B06E6),
    }
};

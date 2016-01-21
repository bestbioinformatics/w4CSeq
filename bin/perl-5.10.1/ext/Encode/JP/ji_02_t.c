/*
 !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
 This file was autogenerated by:
 /var/www/html/w4cseq/bin/perl-5.10.1/miniperl ../bin/enc2xs -Q -o ji_02_t.c -f ji_02_t.fnm
 enc2xs VERSION 2.06
*/
#include "encode.h"

static const encpage_t utf8_jis0201_raw[6];

static const U8 enctable[479] = { 239,189,161,239,189,162,239,189,163,239,
189,164,239,189,165,239,189,166,239,189,167,239,189,168,239,189,169,239,189,
170,239,189,171,239,189,172,239,189,173,239,189,174,239,189,175,239,189,176,
239,189,177,239,189,178,239,189,179,239,189,180,239,189,181,239,189,182,239,
189,183,239,189,184,239,189,185,239,189,186,239,189,187,239,189,188,239,189,
189,239,189,190,239,189,191,239,190,128,239,190,129,239,190,130,239,190,131,
239,190,132,239,190,133,239,190,134,239,190,135,239,190,136,239,190,137,239,
190,138,239,190,139,239,190,140,239,190,141,239,190,142,239,190,143,239,190,
144,239,190,145,239,190,146,239,190,147,239,190,148,239,190,149,239,190,150,
239,190,151,239,190,152,239,190,153,239,190,154,239,190,155,239,190,156,239,
190,157,239,190,158,239,190,159,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,
18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,
44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,
70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,
96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,
116,117,118,119,120,121,122,123,124,125,194,128,194,129,194,130,194,131,194,
132,194,133,194,134,194,135,194,136,194,137,194,138,194,139,194,140,194,141,
194,142,194,143,194,144,194,145,194,146,194,147,194,148,194,149,194,150,194,
151,194,152,194,153,194,154,194,155,194,156,194,157,194,158,194,159,128,129,
130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,
149,150,151,152,153,154,155,156,157,158,159,192,193,194,195,196,197,198,199,
200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,
219,220,221,222,223,161,162,163,164,165,166,167,168,169,170,171,172,173,174,
175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,226,128,
190,126,127 };

static const encpage_t jis0201_raw_utf8[6] = {
{enctable + 189,jis0201_raw_utf8,0x00,0x7d,1,1},
{enctable + 474,jis0201_raw_utf8,0x7e,0x7e,3,1},
{enctable + 478,jis0201_raw_utf8,0x7f,0x7f,1,1},
{enctable + 315,jis0201_raw_utf8,0x80,0x9f,2,1},
{enctable + 0,jis0201_raw_utf8,0xa1,0xdf,3,1},
{0,jis0201_raw_utf8,0xe0,0xff,0,0},
};

static const encpage_t utf8_jis0201_raw_c2[2] = {
{enctable + 379,utf8_jis0201_raw,0x80,0x9f,1,1},
{0,utf8_jis0201_raw_c2,0xa0,0xff,0,0},
};

static const encpage_t utf8_jis0201_raw_e2_80[2] = {
{enctable + 477,utf8_jis0201_raw,0xbe,0xbe,1,1},
{0,utf8_jis0201_raw_e2_80,0xbf,0xff,0,0},
};

static const encpage_t utf8_jis0201_raw_e2[2] = {
{0,utf8_jis0201_raw_e2_80,0x80,0x80,0,2},
{0,utf8_jis0201_raw_e2,0x81,0xff,0,0},
};

static const encpage_t utf8_jis0201_raw_ef_bd[2] = {
{enctable + 443,utf8_jis0201_raw,0xa1,0xbf,1,1},
{0,utf8_jis0201_raw_ef_bd,0xc0,0xff,0,0},
};

static const encpage_t utf8_jis0201_raw_ef_be[2] = {
{enctable + 411,utf8_jis0201_raw,0x80,0x9f,1,1},
{0,utf8_jis0201_raw_ef_be,0xa0,0xff,0,0},
};

static const encpage_t utf8_jis0201_raw_ef[3] = {
{0,utf8_jis0201_raw_ef_bd,0xbd,0xbd,0,2},
{0,utf8_jis0201_raw_ef_be,0xbe,0xbe,0,2},
{0,utf8_jis0201_raw_ef,0xbf,0xff,0,0},
};

static const encpage_t utf8_jis0201_raw[6] = {
{enctable + 189,utf8_jis0201_raw,0x00,0x7d,1,1},
{enctable + 478,utf8_jis0201_raw,0x7f,0x7f,1,1},
{0,utf8_jis0201_raw_c2,0xc2,0xc2,0,2},
{0,utf8_jis0201_raw_e2,0xe2,0xe2,0,3},
{0,utf8_jis0201_raw_ef,0xef,0xef,0,3},
{0,utf8_jis0201_raw,0xf0,0xff,0,0},
};
static const U8 jis0201_raw_encoding_rep_character[] = "\x3F";
static const char jis0201_raw_encoding_enc_name[] = "jis0201-raw";

 const encode_t jis0201_raw_encoding = 
 {jis0201_raw_utf8,utf8_jis0201_raw,jis0201_raw_encoding_rep_character,1,1,1,{jis0201_raw_encoding_enc_name,(const char *)0}};


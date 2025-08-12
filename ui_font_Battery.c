/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font /Users/gjonesblackcyton/Documents/src/matouch/klaussometerV4/SL/assets/Battery Icons.otf -o /Users/gjonesblackcyton/Documents/src/matouch/klaussometerV4/SL/assets/ui_font_Battery.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_BATTERY
#define UI_FONT_BATTERY 1
#endif

#if UI_FONT_BATTERY

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x66, 0x77, 0x8d, 0xed, 0x7b, 0xcf, 0xe1, 0x1e,
    0x78, 0x7e, 0xa, 0xa9, 0xff, 0xef, 0x77, 0xf0,
    0x30, 0xf8,

    /* U+0022 "\"" */
    0x3b, 0xf8, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0023 "#" */
    0x39, 0xfe, 0x4d, 0xd9, 0x30, 0x7f, 0xc1, 0xbb,
    0x7, 0xf8,

    /* U+0024 "$" */
    0x39, 0xff, 0xfe, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0xff, 0xf8,

    /* U+0025 "%" */
    0x3b, 0xf8, 0x61, 0x86, 0xfc, 0x6f, 0x96, 0x1f,
    0xc0,

    /* U+0026 "&" */
    0x33, 0x38, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+0027 "'" */
    0x33, 0x38, 0x6d, 0xa6, 0x18, 0x61, 0xb6, 0x1f,
    0xc0,

    /* U+0028 "(" */
    0x79, 0x8e, 0xc, 0x18, 0x30, 0x7f, 0xff, 0xff,
    0xff, 0xf8,

    /* U+0029 ")" */
    0x3f, 0xf0, 0x40, 0x20, 0xa1, 0x21, 0x42, 0x42,
    0x1, 0x7, 0xfe, 0x0, 0x0, 0x6a, 0x9f, 0xf5,
    0x9e, 0xf3, 0x50, 0x15, 0x63, 0x7e, 0x9a, 0xfb,
    0xc0,

    /* U+002A "*" */
    0x3f, 0xf0, 0x40, 0x20, 0xa1, 0x21, 0x42, 0x42,
    0x1, 0x7, 0xfe, 0x0, 0x0, 0x6a, 0x9f, 0xf5,
    0x9e, 0xf3, 0x50, 0x15, 0x63, 0x7e, 0x9a, 0xfb,
    0xc0,

    /* U+002B "+" */
    0x3f, 0xf0, 0x40, 0x20, 0xa1, 0x21, 0x42, 0x42,
    0x1, 0x7, 0xfe, 0x0, 0x0, 0x6a, 0x9f, 0xf5,
    0x9e, 0xf3, 0x50, 0x15, 0x63, 0x7e, 0x9a, 0xfb,
    0xc0,

    /* U+002C "," */
    0x33, 0x38, 0x61, 0x86, 0x18, 0x61, 0x86, 0x1f,
    0xc0,

    /* U+002D "-" */
    0x33, 0x38, 0x61, 0x86, 0x18, 0x63, 0xbf, 0xff,
    0xc0,

    /* U+002E "." */
    0x33, 0x38, 0x61, 0x86, 0xff, 0xff, 0xff, 0xff,
    0xc0,

    /* U+002F "/" */
    0x33, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0,

    /* U+0030 "0" */
    0x33, 0x38, 0x6d, 0xa6, 0x18, 0x61, 0xb6, 0x1f,
    0xc0,

    /* U+0031 "1" */
    0x33, 0x38, 0x23, 0xb5, 0xdb, 0xf9, 0x86, 0x1f,
    0xc0,

    /* U+0032 "2" */
    0x33, 0x3f, 0xff, 0xff, 0x7e, 0xff, 0xff, 0xff,
    0xc0,

    /* U+0033 "3" */
    0x33, 0x3f, 0xff, 0xcf, 0x3c, 0xff, 0xff, 0xff,
    0xc0,

    /* U+0034 "4" */
    0x33, 0x3f, 0xbf, 0xd5, 0xdf, 0xff, 0xfd, 0xff,
    0xc0,

    /* U+0035 "5" */
    0x33, 0x3f, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0,

    /* U+0036 "6" */
    0x39, 0xff, 0xfe, 0xbd, 0x78, 0xf1, 0xe3, 0xd7,
    0x8f, 0xf8,

    /* U+0037 "7" */
    0x1c, 0x3f, 0x9f, 0x4c, 0xc6, 0xd1, 0xf9, 0xf8,
    0xb6, 0x33, 0x21, 0xbf, 0xc0,

    /* U+0038 "8" */
    0x39, 0xff, 0xfe, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0xf8,

    /* U+0039 "9" */
    0x39, 0xff, 0xfe, 0x3c, 0x78, 0xf1, 0xff, 0xff,
    0x8f, 0xf8,

    /* U+003A ":" */
    0x39, 0xff, 0xfe, 0x3c, 0x7f, 0xff, 0xff, 0xff,
    0x8f, 0xf8,

    /* U+003B ";" */
    0x19, 0xff, 0xf, 0xdf, 0xbf, 0x7e, 0xfd, 0xfb,
    0x87, 0xf8,

    /* U+003C "<" */
    0x39, 0xff, 0xff, 0xff, 0xf9, 0xfb, 0xf7, 0xff,
    0x8f, 0xf8,

    /* U+003D "=" */
    0x1c, 0x3f, 0x9f, 0xcf, 0x47, 0xd3, 0xf9, 0x78,
    0xbe, 0x77, 0x3f, 0xbf, 0xc0,

    /* U+003E ">" */
    0x39, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xef,
    0xff, 0xf8,

    /* U+003F "?" */
    0x0,

    /* U+0040 "@" */
    0x3f, 0xf0, 0x40, 0x20, 0xa1, 0x21, 0x42, 0x42,
    0x1, 0x7, 0xfe, 0x0, 0x0, 0x6a, 0x9f, 0xf5,
    0x9e, 0xf3, 0x50, 0x15, 0x63, 0x7e, 0x9a, 0xfb,
    0xc0,

    /* U+0041 "A" */
    0x33, 0xf8, 0x61, 0xfe, 0x18, 0x7f, 0x86, 0x1f,
    0xc0,

    /* U+0042 "B" */
    0x7b, 0xff, 0xff, 0xdf, 0x3f, 0xff, 0xdf, 0xff,
    0xc0,

    /* U+0043 "C" */
    0x1f, 0x7, 0xf1, 0xff, 0x7f, 0xfe, 0x5b, 0xeb,
    0x7f, 0xff, 0xff, 0x7f, 0xc7, 0xf0, 0x7c, 0x0,

    /* U+0044 "D" */
    0x1f, 0x83, 0xfc, 0x7f, 0xef, 0xff, 0xeb, 0xbe,
    0xbb, 0xff, 0xff, 0xff, 0x7f, 0xe3, 0xfc, 0x1f,
    0x80,

    /* U+0045 "E" */
    0x38, 0xfa, 0xd, 0xd8, 0x37, 0x6e, 0xc1, 0xbb,
    0x5, 0xf0,

    /* U+0046 "F" */
    0x21, 0x3f, 0x18, 0xff, 0xff, 0xff, 0xc8,

    /* U+0047 "G" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf8,

    /* U+0048 "H" */
    0x33, 0xff, 0xff, 0xff, 0x7e, 0xff, 0xff, 0xff,
    0xc0,

    /* U+0049 "I" */
    0xff, 0x7, 0xef, 0x9f, 0xbe, 0x6e, 0xfd, 0xbb,
    0xf7, 0xf8,

    /* U+004A "J" */
    0x3b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0,

    /* U+004B "K" */
    0x33, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f,
    0xc0,

    /* U+004C "L" */
    0x27, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,

    /* U+004D "M" */
    0x33, 0xfe, 0xfb, 0xef, 0xbe, 0xfb, 0xef, 0xbf,
    0xc0,

    /* U+004E "N" */
    0xf, 0x83, 0xfc, 0x7f, 0xee, 0x6f, 0xfb, 0x7f,
    0xfb, 0xf7, 0x7f, 0xff, 0x7f, 0xe3, 0xfc, 0x1f,
    0x0,

    /* U+004F "O" */
    0x1f, 0x7, 0xf1, 0xff, 0x60, 0x7f, 0xf7, 0xc7,
    0x7f, 0xdf, 0xff, 0x7f, 0xc7, 0xf0, 0x7c, 0x0,

    /* U+0050 "P" */
    0x1f, 0x7, 0xf1, 0xff, 0x70, 0x7f, 0xff, 0xdf,
    0x7f, 0xff, 0xff, 0x7f, 0xc7, 0xf0, 0x7c, 0x0,

    /* U+0051 "Q" */
    0x1f, 0x7, 0xf1, 0xff, 0x70, 0x7f, 0xf7, 0xff,
    0x7f, 0xdf, 0xff, 0x7f, 0xc7, 0xf0, 0x7c, 0x0,

    /* U+0052 "R" */
    0x33, 0xff, 0xff, 0xfe, 0x18, 0x7f, 0x86, 0x1f,
    0xc0,

    /* U+0053 "S" */
    0x33, 0xff, 0xff, 0xff, 0xff, 0xff, 0x86, 0x1f,
    0xc0,

    /* U+0054 "T" */
    0x33, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0,

    /* U+0055 "U" */
    0x33, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0,

    /* U+0056 "V" */
    0x33, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff,
    0xc0,

    /* U+0057 "W" */
    0x33, 0xff, 0xff, 0xff, 0x3f, 0xf7, 0xff, 0xff,
    0xc0,

    /* U+0058 "X" */
    0x19, 0xfe, 0xd, 0x1a, 0xb7, 0x6e, 0xc9, 0x93,
    0x7, 0xf8,

    /* U+0059 "Y" */
    0x11, 0xfe, 0xec, 0x1b, 0xb7, 0x60, 0xdd, 0x83,
    0x77, 0xf8,

    /* U+005A "Z" */
    0x11, 0xfe, 0x4c, 0x98, 0x30, 0x60, 0xc1, 0x83,
    0x27, 0xf8,

    /* U+005B "[" */
    0x11, 0xfe, 0xc, 0xdb, 0x36, 0x62, 0xc9, 0x83,
    0x7, 0xf8,

    /* U+005C "\\" */
    0x66, 0x77, 0x8d, 0xed, 0x7b, 0xcf, 0xe1, 0x1e,
    0x78, 0x7e, 0xa, 0xa9, 0xff, 0xef, 0x77, 0xf0,
    0x30, 0xf8,

    /* U+005D "]" */
    0x66, 0x77, 0x8d, 0xed, 0x7b, 0xcf, 0xe1, 0x1e,
    0x78, 0x7e, 0xa, 0xa9, 0xff, 0xef, 0x77, 0xf0,
    0x30, 0xf8,

    /* U+005E "^" */
    0xaf, 0xf7, 0x58, 0xed, 0x7b, 0xcf, 0xe1, 0x1e,
    0xfc, 0x3d, 0x42, 0xa9, 0xd6, 0xef, 0x77, 0xf0,
    0x30, 0xf8,

    /* U+005F "_" */
    0xaf, 0xf7, 0x58, 0xed, 0x7b, 0xcf, 0xe1, 0x1e,
    0xfc, 0x3d, 0x42, 0xa9, 0xd6, 0xef, 0x77, 0xf0,
    0x30, 0xf8,

    /* U+0060 "`" */
    0xaf, 0xf7, 0x58, 0xed, 0x7b, 0xcf, 0xe1, 0x1e,
    0xfc, 0x3d, 0x42, 0xa9, 0xd6, 0xef, 0x77, 0xf0,
    0x30, 0xf8,

    /* U+0061 "a" */
    0x11, 0xfe, 0xc, 0x1b, 0xba, 0xf3, 0xdd, 0x83,
    0x7, 0xf8,

    /* U+0062 "b" */
    0x79, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1, 0xff,
    0xff, 0xf8,

    /* U+0063 "c" */
    0x39, 0xfb, 0xbf, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0x9f, 0xf0,

    /* U+0064 "d" */
    0x79, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1, 0xff,
    0xff, 0xf8,

    /* U+0065 "e" */
    0x79, 0x9e, 0xc, 0x1a, 0x37, 0x6e, 0xc9, 0x93,
    0x7, 0xf8,

    /* U+0066 "f" */
    0x39, 0xde, 0x4c, 0x98, 0x30, 0x7f, 0xff, 0xff,
    0xdf, 0xf8,

    /* U+0067 "g" */
    0x30, 0xfe, 0x82, 0xfe, 0x86, 0x89, 0x8b, 0x86,
    0x82, 0xfe, 0xfe,

    /* U+0068 "h" */
    0x30, 0x7f, 0x24, 0x9f, 0xc8, 0x64, 0x4a, 0x3b,
    0x16, 0x82, 0x7f, 0x3f, 0x80,

    /* U+0069 "i" */
    0x11, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xdb,
    0xff, 0xf8,

    /* U+006A "j" */
    0x31, 0xff, 0xee, 0xdf, 0x3f, 0x7a, 0xfd, 0xbb,
    0xd7, 0xf8,

    /* U+006B "k" */
    0x31, 0xfe, 0xc, 0x19, 0xbf, 0x7a, 0xd9, 0xa3,
    0x7, 0xf8,

    /* U+006C "l" */
    0x11, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0xf8,

    /* U+006D "m" */
    0x10, 0xfe, 0x82, 0x8c, 0xb6, 0xa9, 0xa5, 0xa3,
    0x9c, 0x82, 0xfe,

    /* U+006E "n" */
    0x31, 0xfb, 0xf7, 0xfe, 0xdd, 0x3d, 0x7e, 0xfd,
    0xfb, 0xf0,

    /* U+006F "o" */
    0x33, 0xff, 0xfb, 0xef, 0xf8, 0x73, 0xdf, 0xff,
    0xc0,

    /* U+0070 "p" */
    0x33, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0,

    /* U+0071 "q" */
    0x33, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xc0,

    /* U+0072 "r" */
    0x39, 0x8e, 0xc, 0x18, 0x30, 0x7f, 0xff, 0xff,
    0xff, 0xf8,

    /* U+0073 "s" */
    0x33, 0xe8, 0x61, 0x86, 0x18, 0x61, 0xfe, 0x1f,
    0xc0,

    /* U+0074 "t" */
    0x39, 0xfe, 0xc, 0x18, 0x30, 0x60, 0xff, 0xff,
    0x7, 0xf8,

    /* U+0075 "u" */
    0x33, 0xf8, 0x61, 0x87, 0xf8, 0x7f, 0xfe, 0x1f,
    0xc0,

    /* U+0076 "v" */
    0x39, 0xfe, 0xf, 0xf8, 0x3f, 0xe0, 0xff, 0xff,
    0x7, 0xf8,

    /* U+0077 "w" */
    0x39, 0xfe, 0xc, 0x18, 0x3f, 0x7e, 0xff, 0xff,
    0x7, 0xf8,

    /* U+0078 "x" */
    0x39, 0xfe, 0xc, 0x19, 0x37, 0x64, 0xc9, 0x83,
    0x7, 0xf8,

    /* U+0079 "y" */
    0x39, 0xfe, 0xc, 0x19, 0x32, 0x64, 0xc9, 0x93,
    0x7, 0xf8,

    /* U+007A "z" */
    0x39, 0xfe, 0xc, 0x18, 0x30, 0x67, 0xf1, 0x83,
    0x7, 0xf8,

    /* U+007B "{" */
    0x0,

    /* U+007C "|" */
    0x0,

    /* U+007D "}" */
    0x0,

    /* U+007E "~" */
    0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 166, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 19, .adv_w = 113, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 112, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 113, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 48, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 66, .adv_w = 105, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 119, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 252, .box_w = 15, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 252, .box_w = 15, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 252, .box_w = 15, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 103, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 105, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 104, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 103, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 119, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 214, .adv_w = 104, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 223, .adv_w = 103, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 121, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 123, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 283, .adv_w = 121, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 118, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 121, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 313, .adv_w = 121, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 146, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 336, .adv_w = 119, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 346, .adv_w = 94, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 252, .box_w = 15, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 381, .adv_w = 109, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 390, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 190, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 87, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 440, .adv_w = 117, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 450, .adv_w = 118, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 123, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 469, .adv_w = 117, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 103, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 487, .adv_w = 89, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 104, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 194, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 520, .adv_w = 190, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 536, .adv_w = 192, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 552, .adv_w = 194, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 568, .adv_w = 104, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 577, .adv_w = 105, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 586, .adv_w = 107, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 595, .adv_w = 107, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 106, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 613, .adv_w = 108, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 622, .adv_w = 119, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 632, .adv_w = 115, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 642, .adv_w = 119, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 652, .adv_w = 119, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 662, .adv_w = 166, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 680, .adv_w = 166, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 698, .adv_w = 166, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 716, .adv_w = 166, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 734, .adv_w = 166, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 752, .adv_w = 115, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 762, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 772, .adv_w = 121, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 782, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 792, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 802, .adv_w = 118, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 812, .adv_w = 142, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 823, .adv_w = 151, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 836, .adv_w = 117, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 846, .adv_w = 118, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 856, .adv_w = 119, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 866, .adv_w = 119, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 876, .adv_w = 139, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 887, .adv_w = 127, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 897, .adv_w = 107, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 906, .adv_w = 104, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 915, .adv_w = 102, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 924, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 934, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 943, .adv_w = 112, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 953, .adv_w = 113, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 962, .adv_w = 111, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 972, .adv_w = 113, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 982, .adv_w = 113, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 992, .adv_w = 109, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1002, .adv_w = 115, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1012, .adv_w = 127, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1013, .adv_w = 127, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1014, .adv_w = 127, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1015, .adv_w = 127, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Battery = {
#else
lv_font_t ui_font_Battery = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_BATTERY*/


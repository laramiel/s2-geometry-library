// Copyright 2007 Google Inc. All Rights Reserved.

#include "ascii_ctype.h"

// # Table generated by this Python code (bit 0x02 is currently unused):
// def Hex2(n):
//   return '0x' + hex(n/16)[2:] + hex(n%16)[2:]
// def IsPunct(ch):
//   return (ord(ch) >= 32 and ord(ch) < 127 and
//           not ch.isspace() and not ch.isalnum())
// def IsBlank(ch):
//   return ch in ' \t'
// def IsCntrl(ch):
//   return ord(ch) < 32 or ord(ch) == 127
// def IsXDigit(ch):
//   return ch.isdigit() or ch.lower() in 'abcdef'
// for i in range(128):
//   ch = chr(i)
//   mask = ((ch.isalpha() and 0x01 or 0) |
//           (ch.isalnum() and 0x04 or 0) |
//           (ch.isspace() and 0x08 or 0) |
//           (IsPunct(ch) and 0x10 or 0) |
//           (IsBlank(ch) and 0x20 or 0) |
//           (IsCntrl(ch) and 0x40 or 0) |
//           (IsXDigit(ch) and 0x80 or 0))
//   print Hex2(mask) + ',',
//   if i % 16 == 7:
//     print ' //', Hex2(i & 0x78)
//   elif i % 16 == 15:
//     print
const uint8 kAsciiPropertyBits[256] = {
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  // 0x00
    0x40, 0x68, 0x48, 0x48, 0x48, 0x48, 0x40, 0x40,
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  // 0x10
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x28, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,  // 0x20
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84,  // 0x30
    0x84, 0x84, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x05,  // 0x40
    0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,  // 0x50
    0x05, 0x05, 0x05, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x85, 0x85, 0x85, 0x85, 0x85, 0x85, 0x05,  // 0x60
    0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,  // 0x70
    0x05, 0x05, 0x05, 0x10, 0x10, 0x10, 0x10, 0x40,
};

const unsigned char kAsciiToLower[256] = {
    0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,
    15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,
    45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
    60,  61,  62,  63,  64,  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
    'z', 91,  92,  93,  94,  95,  96,  97,  98,  99,  100, 101, 102, 103, 104,
    105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134,
    135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149,
    150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164,
    165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
    180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194,
    195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
    210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224,
    225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254,
    255};

const unsigned char kAsciiToUpper[256] = {
    0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,
    15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
    30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,
    45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
    60,  61,  62,  63,  64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,
    75,  76,  77,  78,  79,  80,  81,  82,  83,  84,  85,  86,  87,  88,  89,
    90,  91,  92,  93,  94,  95,  96,  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134,
    135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149,
    150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164,
    165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
    180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194,
    195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
    210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224,
    225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254,
    255};

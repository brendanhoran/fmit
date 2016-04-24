// Copyright 2004 "Gilles Degottex"

// This file is part of "fmit"

// "fmit" is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// "fmit" is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#include "GLFreqStruct.h"

static const unsigned char g_icon_formants[] = {
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20,
    0x08, 0x06, 0x00, 0x00, 0x00, 0x73, 0x7a, 0x7a, 0xf4, 0x00, 0x00, 0x06,
    0x99, 0x49, 0x44, 0x41, 0x54, 0x78, 0x9c, 0xb5, 0x97, 0xdd, 0x6f, 0x9b,
    0x57, 0x1d, 0xc7, 0x3f, 0xe7, 0x3c, 0x8f, 0xed, 0x38, 0x4e, 0xec, 0xf8,
    0x35, 0x4e, 0xf3, 0xd2, 0x34, 0x6b, 0xa6, 0x35, 0x81, 0x86, 0x56, 0x5b,
    0xa1, 0xa0, 0x08, 0x84, 0xb8, 0x98, 0x76, 0x91, 0xb1, 0x3f, 0x81, 0x0b,
    0x14, 0xb8, 0xe2, 0x1e, 0xb8, 0xed, 0x0d, 0x48, 0x20, 0xb8, 0x58, 0x15,
    0x10, 0xd3, 0x98, 0x34, 0x81, 0xb6, 0xd2, 0x89, 0x44, 0x53, 0xb7, 0xc1,
    0x5a, 0x90, 0xa7, 0xad, 0xa8, 0x9b, 0x96, 0x76, 0xe9, 0x92, 0x9a, 0xa6,
    0x69, 0xb3, 0xbc, 0xf8, 0x35, 0x49, 0xf3, 0x66, 0x3b, 0xb6, 0xcf, 0xe1,
    0xe2, 0x79, 0x1e, 0xc7, 0xb1, 0xdd, 0xae, 0x42, 0x70, 0xa4, 0x23, 0x9f,
    0xe7, 0xf7, 0x1c, 0x9f, 0xef, 0xe7, 0xf7, 0xfd, 0x1d, 0x9f, 0xc7, 0x8f,
    0xe0, 0xff, 0xd4, 0xc6, 0x27, 0x26, 0x25, 0x10, 0x06, 0x62, 0x00, 0x89,
    0xe9, 0xa9, 0xdb, 0xad, 0xe6, 0x89, 0xff, 0x72, 0xe1, 0x63, 0xc0, 0x09,
    0x60, 0xd0, 0x1e, 0xc7, 0x80, 0x6e, 0xbb, 0x3b, 0xe3, 0x08, 0x60, 0xd4,
    0x7d, 0xf5, 0x06, 0xf0, 0xbd, 0xc4, 0xf4, 0xd4, 0x76, 0xfd, 0x7a, 0xe6,
    0x23, 0x44, 0x02, 0xc0, 0xa9, 0x3a, 0x91, 0xfa, 0xcf, 0x01, 0xc0, 0xfd,
    0x38, 0xc8, 0x0e, 0x9f, 0x97, 0x40, 0x67, 0x07, 0x7e, 0xbf, 0x0f, 0x43,
    0x1a, 0x24, 0xef, 0x2d, 0x73, 0x70, 0x50, 0x7e, 0x0e, 0xf8, 0x01, 0xf0,
    0x9b, 0x96, 0x00, 0xe3, 0x13, 0x93, 0x6e, 0xe0, 0xc7, 0xc0, 0x8b, 0xc0,
    0x78, 0xfd, 0xbd, 0x48, 0xa8, 0x8b, 0x78, 0x2c, 0x44, 0xc0, 0xdf, 0x81,
    0xbf, 0xd3, 0x47, 0x97, 0xbf, 0x03, 0x7f, 0x67, 0x07, 0x01, 0xbf, 0x8f,
    0x40, 0x67, 0x07, 0xed, 0x3e, 0x1f, 0xde, 0x76, 0x1f, 0x1e, 0x8f, 0x17,
    0xd3, 0xed, 0xa5, 0xa2, 0xc0, 0x30, 0x04, 0x5e, 0xb7, 0x24, 0x16, 0x70,
    0xf1, 0xe7, 0xb7, 0xde, 0xe3, 0xe2, 0xab, 0x97, 0x01, 0x5e, 0x6a, 0x09,
    0x60, 0x8b, 0xbf, 0x09, 0x4c, 0x00, 0x9c, 0x3b, 0x33, 0xc2, 0xb9, 0xb3,
    0xa3, 0x9c, 0x1c, 0xec, 0x63, 0xe8, 0x78, 0x2f, 0x6d, 0xed, 0xed, 0x14,
    0x0f, 0x14, 0x85, 0x03, 0x45, 0xe1, 0x40, 0xb3, 0x5f, 0xaa, 0x52, 0x28,
    0x29, 0xf6, 0x4a, 0x8a, 0x9d, 0x83, 0x2a, 0x9b, 0x45, 0x50, 0x05, 0x8d,
    0xd6, 0x1a, 0xa5, 0xf6, 0x50, 0x1a, 0xab, 0x2b, 0xcd, 0x8b, 0xe7, 0x42,
    0x9c, 0x3b, 0x33, 0xea, 0x00, 0x8c, 0x36, 0xba, 0xe5, 0x64, 0xf9, 0x7d,
    0x47, 0xfc, 0xc2, 0x4f, 0x7f, 0xc4, 0xf9, 0x67, 0xc7, 0xc8, 0x6e, 0x97,
    0xc9, 0x6d, 0x57, 0x58, 0x48, 0x2b, 0x6b, 0x51, 0x40, 0x6b, 0x8d, 0x56,
    0xa0, 0xb4, 0x46, 0x69, 0xd0, 0x1a, 0x5c, 0x86, 0xc4, 0x10, 0x1a, 0x8d,
    0xb0, 0x85, 0xeb, 0xe7, 0x08, 0x8a, 0x07, 0x8a, 0xfe, 0xde, 0x18, 0x52,
    0x0a, 0x94, 0xd2, 0x91, 0xf1, 0x89, 0xc9, 0x58, 0x62, 0x7a, 0x2a, 0xd3,
    0x08, 0x10, 0x06, 0xe8, 0xec, 0x68, 0xe7, 0x9b, 0xcf, 0x8d, 0x71, 0x37,
    0x55, 0xa4, 0x50, 0x52, 0x68, 0xc0, 0x65, 0x0a, 0xb4, 0x16, 0x76, 0x76,
    0x02, 0x2d, 0x35, 0xca, 0x16, 0x3b, 0x04, 0x12, 0x96, 0xb0, 0x06, 0x8d,
    0xa0, 0xaa, 0x34, 0x5a, 0x5b, 0x73, 0x8a, 0x15, 0x45, 0xc8, 0xe5, 0x26,
    0x1e, 0x0b, 0xb3, 0x96, 0xca, 0x01, 0x8c, 0x00, 0x4d, 0x00, 0x21, 0x80,
    0xee, 0x68, 0x88, 0xad, 0xbd, 0x2a, 0x4a, 0x81, 0xdb, 0x94, 0x68, 0x38,
    0x5c, 0xd8, 0x16, 0x51, 0x5a, 0xd8, 0xd7, 0xba, 0x2e, 0x76, 0x78, 0xbf,
    0x36, 0x57, 0x69, 0x14, 0x50, 0xae, 0x68, 0x00, 0x06, 0x7a, 0xe3, 0x0e,
    0xc0, 0x28, 0xf0, 0x8f, 0x96, 0x00, 0xb1, 0x48, 0x10, 0xa5, 0x34, 0x2e,
    0x43, 0xa0, 0xc1, 0x5e, 0x0c, 0xdb, 0xfe, 0x16, 0x22, 0x36, 0x84, 0x76,
    0xac, 0xaf, 0x1b, 0x2b, 0xdb, 0xb5, 0x4a, 0xd5, 0x02, 0xe8, 0xef, 0xed,
    0xe6, 0xfa, 0x27, 0x73, 0x8e, 0x03, 0x4d, 0x7b, 0xc0, 0x00, 0x88, 0x86,
    0xbb, 0x70, 0x99, 0xc2, 0xb6, 0xbd, 0x51, 0xbc, 0x35, 0x90, 0xb6, 0x81,
    0x1c, 0x41, 0xd5, 0x00, 0x57, 0x55, 0x8e, 0x03, 0xdd, 0x8e, 0xe6, 0x68,
    0x2b, 0x80, 0x0d, 0x80, 0x6a, 0x55, 0x61, 0x1a, 0x02, 0x97, 0x61, 0xd7,
    0xb8, 0x85, 0xb8, 0x55, 0x96, 0xe6, 0x58, 0xa3, 0x43, 0x0e, 0x50, 0x9b,
    0x5b, 0x36, 0x02, 0x1c, 0x71, 0x40, 0xd6, 0x03, 0xec, 0x17, 0x8a, 0x98,
    0x86, 0xc0, 0x90, 0x16, 0x84, 0x4b, 0x62, 0x7d, 0xda, 0xdd, 0x34, 0x45,
    0x0d, 0xb0, 0xd6, 0x4d, 0x59, 0x37, 0xb6, 0xae, 0xdd, 0xa6, 0x20, 0xd2,
    0x69, 0xf2, 0x4c, 0xaf, 0x97, 0x81, 0x88, 0xc7, 0x2e, 0x41, 0xdc, 0xd1,
    0x8c, 0x8e, 0x4f, 0x4c, 0x46, 0x5b, 0x3a, 0xb0, 0x5f, 0x28, 0x61, 0x48,
    0x4b, 0x44, 0x03, 0x34, 0x66, 0xc8, 0x61, 0x9d, 0x0f, 0xe3, 0x87, 0x31,
    0x04, 0xb4, 0x7b, 0x24, 0x5d, 0xed, 0x26, 0x2e, 0xf3, 0xe8, 0x29, 0x1f,
    0x09, 0x05, 0x68, 0xf7, 0xb6, 0xb1, 0x5f, 0x28, 0x3a, 0x2e, 0xfc, 0xb3,
    0xa5, 0x03, 0x52, 0x80, 0x69, 0x80, 0x29, 0xad, 0xd3, 0xcc, 0xb0, 0x1d,
    0x31, 0x0d, 0x81, 0x29, 0x25, 0xa6, 0x33, 0x36, 0x84, 0x35, 0xcf, 0xce,
    0x3c, 0xe0, 0x33, 0xe9, 0x0b, 0xbb, 0x89, 0xfa, 0x5d, 0x4d, 0xe2, 0x4e,
    0x6b, 0xb5, 0x0f, 0x1a, 0x1c, 0x28, 0x22, 0x85, 0x25, 0xe8, 0x64, 0x48,
    0x2d, 0x73, 0x27, 0x63, 0x3b, 0x5b, 0x7b, 0xec, 0x71, 0x09, 0xda, 0x3d,
    0x12, 0x43, 0x7e, 0xf9, 0x73, 0x6d, 0xb0, 0xbf, 0x87, 0x85, 0xbb, 0x0f,
    0x1c, 0x07, 0x5a, 0x03, 0x08, 0x41, 0x03, 0x80, 0x75, 0xca, 0x35, 0x02,
    0x99, 0x52, 0xd0, 0xe6, 0x7e, 0x32, 0xe1, 0x1a, 0xc0, 0x40, 0x8f, 0x33,
    0x6c, 0x02, 0xc8, 0x03, 0xec, 0xec, 0xee, 0x03, 0x20, 0x05, 0x68, 0x61,
    0x8b, 0x09, 0x61, 0x67, 0x7b, 0x08, 0xe4, 0x32, 0x0d, 0xdc, 0x8f, 0xb0,
    0xf9, 0xb1, 0x00, 0xfd, 0x35, 0x80, 0x5a, 0x09, 0x24, 0x40, 0x62, 0x7a,
    0x6a, 0x13, 0xd8, 0xdd, 0xd9, 0xdd, 0x67, 0x6f, 0xbf, 0x80, 0x21, 0x05,
    0x86, 0x10, 0x48, 0x29, 0x90, 0xd2, 0x02, 0x92, 0x12, 0x0c, 0x09, 0x5e,
    0xb7, 0x6c, 0x29, 0xae, 0xb5, 0x66, 0x65, 0x3d, 0xdb, 0x14, 0x57, 0x4e,
    0xbd, 0x8e, 0x02, 0xc4, 0xc6, 0x27, 0x26, 0xc3, 0x35, 0x00, 0xbb, 0xdd,
    0x03, 0x58, 0x4f, 0xe7, 0x10, 0x02, 0x84, 0xb0, 0x85, 0x6d, 0x10, 0x43,
    0x0a, 0x3c, 0xa6, 0x44, 0x4a, 0xc1, 0xee, 0xde, 0x7e, 0x93, 0xd0, 0x8d,
    0xd9, 0x79, 0x7e, 0x76, 0xe1, 0xe5, 0xa6, 0xf8, 0x85, 0x5f, 0xbd, 0xc2,
    0xe7, 0x77, 0x96, 0x00, 0x88, 0xc7, 0xc2, 0xb8, 0xdd, 0xae, 0x23, 0x2e,
    0xd4, 0x03, 0x2c, 0x01, 0xac, 0xa5, 0x72, 0x96, 0xe8, 0x11, 0x08, 0x30,
    0xa5, 0x40, 0x08, 0x58, 0x5e, 0x49, 0xf1, 0x93, 0x9f, 0xff, 0xfa, 0x48,
    0x66, 0x00, 0x91, 0x70, 0x17, 0xd9, 0x8d, 0x2d, 0xb2, 0xf9, 0xad, 0x23,
    0xf1, 0x42, 0xa9, 0xc4, 0x3b, 0xd7, 0x3e, 0x02, 0x40, 0x4a, 0xc9, 0xf1,
    0xbe, 0xda, 0x79, 0x30, 0xf2, 0x08, 0x07, 0xf2, 0x20, 0x40, 0x08, 0xc1,
    0xec, 0x5c, 0x92, 0x77, 0xaf, 0x5d, 0x47, 0x0a, 0x4b, 0x1c, 0xc0, 0xe5,
    0x32, 0x49, 0x65, 0xf2, 0xac, 0x5b, 0x0f, 0x96, 0x5a, 0x3b, 0xde, 0x1b,
    0xc7, 0xdb, 0xe6, 0xe1, 0xb3, 0xf9, 0xbb, 0x00, 0xcc, 0x27, 0xef, 0x03,
    0x10, 0x0d, 0x87, 0xc8, 0xe4, 0x36, 0x6b, 0xf3, 0x1a, 0xf7, 0x41, 0xb3,
    0x03, 0xe9, 0xac, 0xf5, 0x47, 0x51, 0xc0, 0x8d, 0xd9, 0xcf, 0x79, 0xfb,
    0xef, 0x1f, 0xd6, 0xc4, 0x1d, 0x1b, 0x03, 0x9d, 0x3e, 0x3e, 0xfd, 0x2c,
    0x79, 0x04, 0xc0, 0x30, 0x24, 0xf1, 0x58, 0x98, 0xbb, 0x4b, 0x2b, 0x00,
    0xfc, 0xf6, 0x0f, 0x6f, 0x90, 0xcd, 0x6f, 0x12, 0x8f, 0x86, 0xc9, 0xe6,
    0x0e, 0x5d, 0xf9, 0x52, 0x07, 0xec, 0x47, 0x26, 0x02, 0x78, 0x66, 0x68,
    0x80, 0x54, 0x3a, 0x47, 0xa5, 0x5a, 0x25, 0x93, 0xdb, 0xe4, 0xca, 0xd5,
    0x0f, 0x11, 0x42, 0xd0, 0x1d, 0x8b, 0xb0, 0xbc, 0xba, 0x0e, 0xc0, 0xcc,
    0x7b, 0x1f, 0x90, 0x5c, 0x5c, 0xb6, 0xb3, 0x0d, 0x92, 0xcd, 0x5b, 0xd9,
    0xf6, 0x44, 0x23, 0x7c, 0x3c, 0xbb, 0xc0, 0x57, 0x4f, 0x9d, 0x20, 0x93,
    0xdf, 0xac, 0xed, 0x9b, 0xc7, 0x39, 0x50, 0xdb, 0x84, 0x4e, 0x3b, 0x3d,
    0x3a, 0x4c, 0xb1, 0x58, 0x62, 0xf9, 0x8b, 0x14, 0x2b, 0xeb, 0x19, 0xde,
    0xbd, 0xf6, 0x2f, 0x00, 0x62, 0x91, 0xae, 0x5a, 0xad, 0xb7, 0x77, 0xf7,
    0x78, 0xff, 0x83, 0x8f, 0xed, 0x78, 0x90, 0x8c, 0x9d, 0x6d, 0x6f, 0x4f,
    0x84, 0xb5, 0x54, 0x96, 0x93, 0x43, 0x03, 0x18, 0x52, 0x30, 0xff, 0xef,
    0x07, 0x00, 0x84, 0x43, 0x01, 0x67, 0xf9, 0xee, 0xf1, 0x89, 0xc9, 0x50,
    0x3d, 0xc0, 0x7d, 0x40, 0xaf, 0xa7, 0xf3, 0x68, 0x7b, 0x83, 0x85, 0x82,
    0x7e, 0x82, 0x41, 0x3f, 0x9f, 0xdc, 0x5a, 0xe0, 0xd4, 0xf0, 0x20, 0xf9,
    0x8d, 0x87, 0x96, 0x50, 0x38, 0x58, 0xab, 0x6b, 0xff, 0xb1, 0x18, 0xab,
    0x6b, 0xd6, 0xcf, 0x6f, 0x68, 0xb0, 0x8f, 0x54, 0x26, 0x8f, 0xd2, 0x9a,
    0x63, 0xf1, 0x28, 0xeb, 0x99, 0x0d, 0xda, 0x3c, 0x6e, 0x62, 0xd1, 0x30,
    0xb7, 0xec, 0xbd, 0xd1, 0xe6, 0xf1, 0xd4, 0x57, 0xae, 0xad, 0x06, 0x90,
    0x98, 0x9e, 0x2a, 0x00, 0xa9, 0x72, 0xa5, 0x42, 0x6e, 0xe3, 0xb0, 0x66,
    0xdd, 0xb1, 0x10, 0x6b, 0xe9, 0x1c, 0xde, 0x36, 0x0f, 0x86, 0x21, 0xd9,
    0xde, 0xd9, 0xe3, 0xe9, 0xa7, 0x06, 0x48, 0x65, 0xf2, 0x94, 0x2b, 0x15,
    0xc6, 0x46, 0x86, 0x59, 0xb3, 0x5d, 0xfb, 0xda, 0xe8, 0x30, 0xbb, 0x7b,
    0x05, 0x56, 0xd7, 0x32, 0x8c, 0x8d, 0x0e, 0xb3, 0xbc, 0x9a, 0xaa, 0x39,
    0x93, 0xcd, 0x6e, 0x52, 0x28, 0x96, 0x78, 0xe5, 0x4f, 0x33, 0xce, 0xd2,
    0x55, 0x20, 0xdd, 0xf8, 0x5e, 0x70, 0x0f, 0xe8, 0x59, 0x4b, 0xe5, 0x88,
    0x86, 0x83, 0xb5, 0x6c, 0xd3, 0x99, 0x4d, 0xdb, 0xd6, 0x18, 0x9f, 0xce,
    0x25, 0x39, 0x3d, 0x72, 0x92, 0x83, 0x83, 0x32, 0xf7, 0x97, 0x53, 0x0c,
    0x0f, 0xf5, 0xa1, 0x94, 0xa2, 0x58, 0x2c, 0xd1, 0x1d, 0x0d, 0x12, 0xe8,
    0x6c, 0x67, 0x76, 0x2e, 0xc9, 0x37, 0x9e, 0xfd, 0x0a, 0x1b, 0x9b, 0x0f,
    0x79, 0xed, 0x8d, 0xb7, 0x59, 0xbc, 0xbf, 0x42, 0x2e, 0xbf, 0xc5, 0x95,
    0xab, 0x1f, 0xd5, 0xdc, 0x05, 0x2e, 0x27, 0xa6, 0xa7, 0xaa, 0x8d, 0x00,
    0x4b, 0xc0, 0xb7, 0xd6, 0xd3, 0x39, 0xc6, 0x46, 0x87, 0x01, 0x88, 0x47,
    0xc3, 0x24, 0x17, 0xad, 0xfa, 0x1d, 0x8b, 0x47, 0xf8, 0x62, 0x35, 0xc5,
    0xb7, 0xcf, 0x9f, 0x21, 0x14, 0xec, 0xe2, 0xe6, 0xed, 0x24, 0x27, 0x8e,
    0xf7, 0xe0, 0x6d, 0x73, 0xf3, 0xda, 0x9b, 0x57, 0x28, 0x97, 0x2b, 0x94,
    0x95, 0xe6, 0xe2, 0x1f, 0xdf, 0xe2, 0x97, 0x2f, 0xbf, 0x8e, 0xd6, 0x9a,
    0xdf, 0xbf, 0x3e, 0x83, 0x7d, 0x88, 0x23, 0x10, 0x15, 0xe0, 0x0e, 0xf0,
    0x17, 0xe0, 0x17, 0xd0, 0xfc, 0x66, 0xb4, 0x08, 0x70, 0xfb, 0xce, 0x12,
    0xcf, 0x7f, 0xf7, 0x3c, 0x00, 0x67, 0x4f, 0x3f, 0xcd, 0xa5, 0x99, 0xf7,
    0xd9, 0xdb, 0x2f, 0x10, 0xea, 0xf2, 0x33, 0x3b, 0x97, 0xe4, 0xd2, 0xcc,
    0x55, 0x94, 0x56, 0x5c, 0x9a, 0xb9, 0xca, 0xc5, 0x57, 0x2f, 0x53, 0xae,
    0x94, 0x99, 0x5b, 0x58, 0x3a, 0xf2, 0x73, 0x05, 0xb2, 0x02, 0x31, 0x07,
    0xcc, 0x82, 0xb8, 0xa9, 0x94, 0x58, 0x14, 0x52, 0xdf, 0x48, 0x4c, 0x4f,
    0x95, 0xea, 0x27, 0x1d, 0xf9, 0xca, 0xf8, 0xc4, 0xe4, 0xd7, 0x81, 0xeb,
    0x6e, 0x97, 0xc9, 0x4b, 0x2f, 0x7c, 0x07, 0xbf, 0xdf, 0xc7, 0xc3, 0x87,
    0x3b, 0xfc, 0xf5, 0x9d, 0x04, 0x9d, 0x1d, 0x3e, 0x72, 0xf9, 0x2d, 0xb4,
    0x68, 0x7a, 0xa1, 0x2c, 0x83, 0x5e, 0x52, 0x82, 0x07, 0x52, 0x8b, 0xbf,
    0x01, 0xb7, 0x80, 0x5b, 0x89, 0xe9, 0xa9, 0x75, 0x9e, 0xa0, 0x35, 0x3d,
    0x55, 0xc6, 0x27, 0x26, 0x7f, 0x07, 0xfc, 0xb0, 0x3e, 0xa6, 0x35, 0x4e,
    0x76, 0x69, 0xe0, 0xa6, 0x23, 0x62, 0xf7, 0xf9, 0xc4, 0xf4, 0xd4, 0xc1,
    0x93, 0x88, 0x3d, 0x11, 0x80, 0x0d, 0x71, 0x16, 0x78, 0x01, 0x78, 0x0a,
    0x98, 0x73, 0x44, 0xeb, 0xdf, 0x68, 0xfe, 0x57, 0xed, 0x3f, 0x3b, 0xa5,
    0x53, 0x06, 0x63, 0xf4, 0x8e, 0x8b, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45,
    0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

#include <iostream>
using namespace std;
#include <qtooltip.h>
#include <qimage.h>
#include <qboxlayout.h>
#include <qwidgetaction.h>
#include <Music/Music.h>
using namespace Music;

GLFreqStruct::GLFreqStruct(QWidget* parent)
: QGLWidget(parent)
, View(tr("Harmonics"), this)
, m_font("Helvetica")
, m_components_max(1.0)
{
	// settings
	QPixmap img;
	img.loadFromData(g_icon_formants, sizeof(g_icon_formants), "PNG");
	setting_show->setIcon(QIcon(img));
	setting_show->setChecked(false);
	hide();

	QHBoxLayout* numComponentsActionLayout = new QHBoxLayout(&m_popup_menu);

	QLabel* numComponentsActionTitle = new QLabel(tr("Number of harmonics"), &m_popup_menu);
	numComponentsActionLayout->addWidget(numComponentsActionTitle);

	setting_spinNumComponents = new QSpinBox(&m_popup_menu);
	setting_spinNumComponents->setMinimum(1);
	setting_spinNumComponents->setMaximum(128);
	setting_spinNumComponents->setSingleStep(1);
	setting_spinNumComponents->setValue(16);
	m_components.resize(setting_spinNumComponents->value());
	setting_spinNumComponents->setToolTip(tr("Number of harmonics"));
	connect(setting_spinNumComponents, SIGNAL(valueChanged(int)), this, SLOT(spinNumComponentsChanged(int)));
	numComponentsActionLayout->addWidget(setting_spinNumComponents);

	QWidget* numComponentsActionWidget = new QWidget(&m_popup_menu);
	numComponentsActionWidget->setLayout(numComponentsActionLayout);

	QWidgetAction* numComponentsAction = new QWidgetAction(&m_popup_menu);
	numComponentsAction->setDefaultWidget(numComponentsActionWidget);
	m_popup_menu.addAction(numComponentsAction);

	for(size_t i=0; i<m_components.size(); i++)
		m_components[i] = 0.0;
}

void GLFreqStruct::save()
{
	s_settings->setValue("spinNumComponents", setting_spinNumComponents->value());
}
void GLFreqStruct::load()
{
	setting_spinNumComponents->setValue(s_settings->value("spinNumComponents", setting_spinNumComponents->value()).toInt());
}
void GLFreqStruct::clearSettings()
{
	s_settings->remove("spinNumComponents");
}

void GLFreqStruct::spinNumComponentsChanged(int num)
{
	m_components.resize(num);
}

void GLFreqStruct::initializeGL()
{
	// Set the clear color to black
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glShadeModel( GL_FLAT );
//	glShadeModel( GL_SMOOTH );

	glLoadIdentity();
}

void GLFreqStruct::paintGL()
{
	if(m_components_max==0.0)	return;

	glClear(GL_COLOR_BUFFER_BIT);

	int scale_height = 12;
    int s = 2+fontMetrics().width("-40dB");

//	double scale_factor = 1.0;
//	if(m_components_max>0.0)
//		scale_factor = 1.0/m_components_max;

    // bars
	glBegin(GL_QUADS);
    float step = float(width()-s)/m_components.size();
	int space = (step>2)?1:0;
	for(size_t i=0; i<m_components.size(); i++)
	{
		glColor3f(0.4, 0.4, 0.5);
//        int y = int( (scale_factor*m_components[i]) * (height()-scale_height)) + scale_height;
        int y = height() + int( (m_components[i]-m_components_max) * (height()-scale_height)/50);

//        std::cout << i << ":" << m_components_max << " " << m_components[i] << " y=" << y << std::endl;

        if(y>0)
		{
            glVertex2i(int(i*step)+s, scale_height);
            glVertex2i(int(i*step)+s, y);
            glVertex2i(int((i+1)*step)+s-space, y);
            glVertex2i(int((i+1)*step)+s-space, scale_height);
		}
	}
	glEnd();

    // horiz lines
    if(2*height()/50>2)
    {
        glBegin(GL_LINES);
        float gray = 0.875;
        glColor3f(gray, gray, gray);
        for(int h=0; h<50; h+=2)
        {
            glVertex2i(s, height()-h*(height()-scale_height)/50);
            glVertex2i(width(), height()-h*(height()-scale_height)/50);
        }
        glEnd();
    }
    if(10*height()/50>2)
    {
        glBegin(GL_LINES);
        float gray = 0.75;
        glColor3f(gray, gray, gray);
        for(int h=0; h<50; h+=10)
        {
            glVertex2i(s, height()-h*(height()-scale_height)/50);
            glVertex2i(width(), height()-h*(height()-scale_height)/50);
        }
        glEnd();
    }

    glColor3f(0.5f,0.5f,0.5f);
    m_font.setPixelSize(14);
    QFontMetrics fm(m_font);
    int dy = -fm.xHeight()/2;
    string sfraq = "-10dB";
    renderText(2, 10*(height()-scale_height)/50-dy, QString(sfraq.c_str()), m_font);
    sfraq = "-20dB";
    renderText(2, 20*(height()-scale_height)/50-dy, QString(sfraq.c_str()), m_font);
    sfraq = "-30dB";
    renderText(2, 30*(height()-scale_height)/50-dy, QString(sfraq.c_str()), m_font);
    sfraq = "-40dB";
    renderText(2, 40*(height()-scale_height)/50-dy, QString(sfraq.c_str()), m_font);

    // scale
    m_font.setPixelSize(10);
    glColor3f(0,0,0);
	for(size_t i=0; i<m_components.size(); i++)
        renderText(int((i+0.5)*step)+s-3, height()-2, QString::number(i+1), m_font);

    // name
    glColor3f(0.75,0.75,0.75);
    m_font.setPixelSize(20);
    renderText(2, 20, tr("Harmonics' amplitude"), m_font);

    glFlush();
}

void GLFreqStruct::resizeGL( int w, int h )
{
	// Set the new viewport size
	glViewport(0, 0, (GLint)w, (GLint)h);

	// Choose the projection matrix to be the matrix
	// manipulated by the following calls
	glMatrixMode(GL_PROJECTION);

	// Set the projection matrix to be the identity matrix
	glLoadIdentity();

	// Define the dimensions of the Orthographic Viewing Volume
	glOrtho(0.0, w, 0.0, h, 0.0, 1.0);

	// Choose the modelview matrix to be the matrix
	// manipulated by further calls
	glMatrixMode(GL_MODELVIEW);
}


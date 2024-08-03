#ifndef _AUX_CONFIG_H
#define _AUX_CONFIG_H
//-----------------------------------------------------
//config macro (but not constant value)
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include <stdint.h>
#include <limits.h>

//predefine constant
#define DBG_ERROR 1
#define AUX_LOG_ENABLE 1



#define __WORD_WIDTH__ CHAR_BIT
#define __WORD_TRAIT__ 0xff
#define __HWORD_WIDTH__ (CHAR_BIT/2)
#define __HWORD_MUL__ 2
#define __HWORD_TRAIT__ 0x0f
#define __BIT_TRAIT__ 0x01

#ifndef __SIZEOF_INT128__
#define SIZEOF__INT128 16
#else
#define SIZEOF__INT128 __SIZEOF_INT128__
#endif

#define __UINT8_WIDTH__ UCHAR_WIDTH
#define __UINT16_WIDTH__ USHRT_WIDTH
#define __UINT32_WIDTH__ UINT_WIDTH
#define __UINT64_WIDTH__ ULLONG_WIDTH
#define __UINT128_WIDTH__ 128

#endif
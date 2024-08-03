#ifndef _AUX_BIT_H
#define _AUX_BIT_H

#include <stdint.h>
#include <limits.h>
#include "aconfig.h"

//---------------------------------------------------
//scm macro function

#ifndef __DEFT
#define __DEFT -1
#endif

//general
//AUX_GET the byte in pos
//exam : AUX_GET_BYTES(0,0xbbaf)=>af
#define AUX_GET_BYTE(pos,var) \
((pos + 1 > sizeof(var)) ? __DEFT :\
((var >> ((pos)*__WORD_WIDTH__)) & __WORD_TRAIT__))

//general
//AUX_GET the half byte in pos
#define AUX_GET_HBYTE(pos,var)\
((pos + 1 > sizeof(var)*__HWORD_MUL__) ? __DEFT :\
((var >> ((pos)*__HWORD_WIDTH__)) & __HWORD_TRAIT__))

//AUX_GET the bit in pos
#define AUX_GET_BIT(pos,var) \
(!!(var & (__BIT_TRAIT__ << (pos))))

//AUX_GET all the bit in range[start,end] 
#define AUX_GET_RANGE(end,start,var) \
((end- start + 1 > sizeof(var)*__WORD_WIDTH__) ?  __DEFT :\
((var << ((sizeof(var)*__WORD_WIDTH__ -1) - (end))) >> ((sizeof(var)*__WORD_WIDTH__-1) - (end) + (start))))

//----------------------------------------------
//AUX_CLEAR macro
//AUX_CLEAR bytes in pos
#define AUX_CLEAR_BYTE(pos,var) \
((pos+1 > sizeof(var)) ? __DEFT:\
(var &= ~(__WORD_TRAIT__ << (pos*__WORD_WIDTH__))))

//AUX_CLEAR half bytes in pos
#define AUX_CLEAR_HBYTE(pos,var) \
((pos+1 > sizeof(var)*__HWORD_MUL__) ? __DEFT:\
(var &= ~(__HWORD_TRAIT__ << (pos*__HWORD_WIDTH__))))

//AUX_CLEAR bits in pos
#define AUX_CLEAR_BIT(pos,var) \
((pos+1 > sizeof(var)*__WORD_WIDTH__) ? __DEFT :\
(var &= ~(__BIT_TRAIT__ << (pos))))

//AUX_CLEAR all the bit in range[start,end] 
#define AUX_CLEAR_RANGE(end,start,var) \
((end- start + 1 > sizeof(var)*__WORD_WIDTH__) ?  __DEFT :\
(var &= ~((ULLONG_MAX << (start)) & (ULLONG_MAX >> (__UINT64_WIDTH__ - 1 - (end) )))))
//-------------------------------------------------
//AUX_SET macro

//AUX_SET bytes in pos with 1
#define AUX_SET_BYTE(pos,var) \
((pos+1 > sizeof(var)) ? __DEFT:\
(var |= (__WORD_TRAIT__ << (pos*__WORD_WIDTH__))))

//AUX_SET half bytes in pos with 1
#define AUX_SET_HBYTE(pos,var) \
((pos+1 > sizeof(var)*__HWORD_MUL__) ? __DEFT:\
(var |= (__HWORD_TRAIT__ << (pos*__HWORD_WIDTH__))))

//AUX_SET bit in pos with 1
#define AUX_SET_BIT(pos,var) \
((pos+1 > sizeof(var)*__WORD_WIDTH__) ? __DEFT :\
(var |= (__BIT_TRAIT__ << (pos))))

//AUX_SET all the bit in range[start,end] with 1
#define AUX_SET_RANGE(end,start,var) \
((end- start + 1 > sizeof(var)*__WORD_WIDTH__) ?  __DEFT :\
(var |= ((ULLONG_MAX << (start)) & (ULLONG_MAX >> (__UINT64_WIDTH__ - 1 - (end) )))))


#endif



#ifndef _AUX_IF_H
#define _AUX_IF_H
#include "aconfig.h"

#define AUX_IF(cond, f, e) AUX_IF_I(cond, f, e)
#define AUX_IF_I(cond, f, e) AUX_IF_II(cond,f,e)
#define AUX_IF_II(cond, f, e) AUX_IF##cond(f, e)
#define AUX_IF0(f, e) e
#define AUX_IF1(f, e) f
#define AUX_EMPTY
#endif
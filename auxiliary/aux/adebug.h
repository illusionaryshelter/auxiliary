#ifndef _AUX_DEBUG_H
#define _AUX_DEBUG_H
#include "aconfig.h"
#include "aif.h"

#if !defined(DBG_ERROR)
#define DBG_ERROR 0
#endif



#define AUX_DBG(cond,statement)\
if(cond)\
do{\
statement;\
}while(0)


#define AUX_DPRG(cond,statement)\
AUX_IF(DBG_ERROR,AUX_DBG(cond,statement),AUX_EMPTY)



#endif
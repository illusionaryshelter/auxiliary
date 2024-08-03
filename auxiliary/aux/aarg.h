#ifndef _AUX_ARG__H_
#define _AUX_ARG__H_
#include "aconfig.h"

#define DFLT -1
#define ARG(X) X  //for msvc
#define _AUX_ARG_NUM(A0,A1,A2,A3,A4,A5,A6,N,...) N
#define AUX_ARG_NUM(...) \
ARG(_AUX_ARG_NUM(__VA_ARGS__,7,6,5,4,3,2,1))
//Series of Macro to get num of arg and a accurate arg
#define _AUX_ARG0(A0,...) A0
#define _AUX_ARG1(A0,A1,...) A1
#define _AUX_ARG2(A0,A1,A2,...) A2
#define _AUX_ARG3(A0,A1,A2,A3,...) A3
#define _AUX_ARG4(A0,A1,A2,A3,A4,...) A4
#define _AUX_ARG5(A0,A1,A2,A3,A4,A5,...) A5
#define _AUX_ARG6(A0,A1,A2,A3,A4,A5,A6,...) A6
#define AUX_ARG0(...)  ARG(_AUX_ARG0(__VA_ARGS__,DFLT))  //
#define AUX_ARG1(...)  ARG(_AUX_ARG1(__VA_ARGS__,DFLT,DFLT))
#define AUX_ARG2(...)  ARG(_AUX_ARG2(__VA_ARGS__,DFLT,DFLT,DFLT))
#define AUX_ARG3(...)  ARG(_AUX_ARG3(__VA_ARGS__,DFLT,DFLT,DFLT,DFLT))
#define AUX_ARG4(...)  ARG(_AUX_ARG4(__VA_ARGS__,DFLT,DFLT,DFLT,DFLT,DFLT))
#define AUX_ARG5(...)  ARG(_AUX_ARG5(__VA_ARGS__,DFLT,DFLT,DFLT,DFLT,DFLT,DFLT))
#define AUX_ARG6(...)  ARG(_AUX_ARG6(__VA_ARGS__,DFLT,DFLT,DFLT,DFLT,DFLT,DFLT,DFLT))
#endif
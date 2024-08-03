#ifndef _AUX_MAP__H_
#define _AUX_MAP__H_
#include "aconfig.h"
#include "aeval.h"

#define MAP_END(...)
#define MAP_OUT
#define MAP_COMMA ,
#define MAP_SEM ;

#define MAP_GET_END2() 0, MAP_END
#define MAP_GET_END1(...) MAP_GET_END2
#define MAP_GET_END(...) MAP_GET_END1
#define MAP_NEXT0(test, next, ...) next MAP_OUT

#define MAP_NEXT1(test, next) MAP_NEXT0(test,MAP_SEM next, 0)
#define MAP_NEXT(test, next)  MAP_NEXT1(MAP_GET_END test, next)

#define MAP_1_II(f, x, peek, ...) f(x) MAP_NEXT(peek, MAP_1_I)(f, peek, __VA_ARGS__)
#define MAP_1_I(f, x, peek, ...) f(x) MAP_NEXT(peek, MAP_1_II)(f, peek, __VA_ARGS__)

#define MAP_2_II(f, x, y,peek, ...) f(x,y) MAP_NEXT(peek, MAP_2_I)(f, peek, __VA_ARGS__)
#define MAP_2_I(f, x,y, peek, ...) f(x,y) MAP_NEXT(peek, MAP_2_II)(f, peek, __VA_ARGS__)

#define MAP_3_II(f, x, y,z,peek, ...) f(x,y,z) MAP_NEXT(peek, MAP_3_I)(f, peek, __VA_ARGS__)
#define MAP_3_I(f, x,y,z, peek, ...) f(x,y,z) MAP_NEXT(peek, MAP_3_II)(f, peek, __VA_ARGS__)

#define MAP_4_II(f, x, y,z,j,peek, ...) f(x,y,z,j) MAP_NEXT(peek, MAP_4_I)(f, peek, __VA_ARGS__)
#define MAP_4_I(f, x,y,z,j, peek, ...) f(x,y,z,j) MAP_NEXT(peek, MAP_4_II)(f, peek, __VA_ARGS__)

#define MAP_5_II(f, x, y,z,j,k,peek, ...) f(x,y,z,j,k) MAP_NEXT(peek, MAP_5_I)(f, peek, __VA_ARGS__)
#define MAP_5_I(f, x,y,z,j,k ,peek, ...) f(x,y,z,j,k) MAP_NEXT(peek, MAP_5_II)(f, peek, __VA_ARGS__)

#define MAP_6_II(f, x, y,z,j,k,p,peek, ...) f(x,y,z,j,k,p) MAP_NEXT(peek, MAP_6_I)(f, peek, __VA_ARGS__)
#define MAP_6_I(f, x,y,z,j,k,p ,peek, ...) f(x,y,z,j,k,p) MAP_NEXT(peek, MAP_6_II)(f, peek, __VA_ARGS__)

#define MAP_7_II(f, x, y,z,j,k,p,q,peek, ...) f(x,y,z,j,k,p,q) MAP_NEXT(peek, MAP_7_I)(f, peek, __VA_ARGS__)
#define MAP_7_I(f, x,y,z,j,k,p ,q,peek, ...) f(x,y,z,j,k,p,q) MAP_NEXT(peek, MAP_7_II)(f, peek, __VA_ARGS__)

#define MAP_E_II(expr,placholder,peek, ...) expr;  MAP_NEXT(peek, MAP_E_I)(expr, peek, __VA_ARGS__)
#define MAP_E_I(expr,placholder,peek, ...) expr;  MAP_NEXT(peek, MAP_E_II)(expr, peek, __VA_ARGS__)

#define MAP1(f, ...) EVAL(MAP_1_I(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))
#define MAP2(f, ...) EVAL(MAP_2_I(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))
#define MAP3(f, ...) EVAL(MAP_3_I(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))
#define MAP4(f, ...) EVAL(MAP_4_I(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))
#define MAP5(f, ...) EVAL(MAP_5_I(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))
#define MAP6(f, ...) EVAL(MAP_6_I(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))
#define MAP7(f, ...) EVAL(MAP_7_I(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))

#define AUX_MAP(n,f,...) MAP_I(n,f,__VA_ARGS__)
#define MAP_I(n,f,...)  MAP##n(f,__VA_ARGS__)
#define AUX_MAP_NUM(i)  i
#endif
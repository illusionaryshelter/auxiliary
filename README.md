# fast_embed
auxiliary macro header


example:

```c++
#define ARRAY_PLAIN(...) {__VA_ARGS__}
#define ARRAY_GEN(name, type, rows, cols, ...) \
	Eigen::Array<type, rows, cols> name({AUX_MAP(cols, ARRAY_PLAIN, __VA_ARGS__)})
```

 the you can write: 

```c++
ARRAY_GEN(s, float, 4, 2,
		1, 2,
		4, 5,
		7, 8,
		10, 11);
```

just for fun.

#include "vec4.h"

// use case : component wise multiplication

t_vec4	vec4_mul(t_vec4 a, t_vec4 b)
{
	t_vec4	res;

	res.r = a.r * b.r;
	res.g = a.g * b.g;
	res.b = a.b * b.b;
	res.a = a.a * b.a;
	return (res);
}

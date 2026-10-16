#include "vec4.h"

// use case : reverse a vector dir

t_vec4	vec4_neg(t_vec4 vec)
{
	t_vec4	res;

	res.x = -vec.x;
	res.y = -vec.y;
	res.z = -vec.z;
	res.w = vec.w;
	return (res);
}

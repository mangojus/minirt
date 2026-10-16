#include "vec4.h"

// use case : scaling up vectors

t_vec4	vec4_scalar_mul(t_vec4 vec, float scalar)
{
	t_vec4	res;

	res.x = vec.x * scalar;
	res.y = vec.y * scalar;
	res.z = vec.z * scalar;
	res.w = vec.w;
	return (res);
}

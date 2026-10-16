#include "vec4.h"

// use case : scaling down vecs

t_vec4	vec4_scalar_div(t_vec4 vec, float scalar)
{
	t_vec4	res;

	if (scalar == 0)
		return (vec);
	res.x = vec.x / scalar;
	res.y = vec.y / scalar;
	res.z = vec.z / scalar;
	res.w = vec.w;
	return (res);
}

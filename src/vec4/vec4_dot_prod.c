#include "vec4.h"

// use case : calc angles between vectors, tests for perpendicularity

float	vec4_dot_prod(t_vec4 a, t_vec4 b)
{
	float	res;

	res = a.x * b.x + a.y * b.y + a.z * b.z;
	return (res);
}

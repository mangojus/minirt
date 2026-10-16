#include "vec4.h"

// use case : move pos coords / find b to a dir vector / substract color

t_vec4	vec4_sub(t_vec4 a, t_vec4 b)
{
	t_vec4	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	res.w = a.w;
	return (res);
}

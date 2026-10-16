#include "vec4.h"

// use case : create new dir vector

t_vec4	vec4_vector(float x, float y, float z)
{
	t_vec4	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 0.0;
	return (vector);
}

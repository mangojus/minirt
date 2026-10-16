#include "vec4.h"

// use case : create new point coords

t_vec4	vec4_point(float x, float y, float z)
{
	t_vec4	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1.0;
	return (point);
}

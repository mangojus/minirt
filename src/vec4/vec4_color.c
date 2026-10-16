#include "vec4.h"

// use case : create new color

t_vec4	vec4_color(float x, float y, float z)
{
	t_vec4	color;

	color.x = x;
	color.y = y;
	color.z = z;
	color.w = 1.0;
	color = vec4_scalar_div(color, 255);
	return (color);
}

#include "vec4.h"
#include "math.h"

// use case : calc vector magnitude

float	vec4_len(t_vec4 vec)
{
	float	len;

	len = sqrt(vec4_dot_prod(vec, vec));
	return (len);
}

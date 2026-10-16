#include "vec4.h"

t_vec4	vec4_mat4_prod(t_vec4 v, const t_mat4 *m)
{
	t_vec4	res;

	res.x = vec4_dot_prod(m->m[0], v);
	res.y = vec4_dot_prod(m->m[1], v);
	res.z = vec4_dot_prod(m->m[2], v);
	res.w = vec4_dot_prod(m->m[3], v);
	if (res.w != 0 && res.w != 1)
	{
		res.x /= res.w;
		res.y /= res.w;
		res.z /= res.w;
	}
	return (res);
}

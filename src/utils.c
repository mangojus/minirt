#include "minirt.h"
#include "mlx.h"

static void	free_objs(t_obj *lst)
{
	t_obj	*tmp;

	while (lst)
	{
		tmp = lst->next;
		ft_nullfree((void **)&lst);
		lst = tmp;
	}
}

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->cam)
		ft_nullfree((void **)&scene->cam);
	if (scene->amb)
		ft_nullfree((void **)&scene->amb);
	if (scene->l)
		ft_nullfree((void **)&scene->l);
	if (scene->objs)
		free_objs(scene->objs);
	if (scene->cy)
		scene->cy = NULL;
	if (scene->pl)
		scene->pl = NULL;
	if (scene->sp)
		scene->sp = NULL;
	ft_nullfree((void **)&scene);
}

void	free_env(t_env *env)
{
	if (!env)
		return ;
	if (env->scene)
		free_scene(env->scene);
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
}

#include "minirt.h"
#include "mlx.h"

int	close_win(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	free_env(env);
	exit (EXIT_SUCCESS);
}

static int	key_controls(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keycode == ESC_KEY)
		close_win((void *)env);
	return (0);
}

void	hook_controls(t_env *env)
{
	mlx_key_hook(env->win, key_controls, (void *)env);
	mlx_hook(env->win, 17, 0, close_win, (void *)env);
}

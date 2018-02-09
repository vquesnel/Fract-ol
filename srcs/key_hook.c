/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:20:52 by vquesnel          #+#    #+#             */
/*   Updated: 2018/02/09 11:37:04 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	modify_moove(t_env *env)
{
	static double	i = 0.2;

	if (env->p->zoom <= 100)
		i = 0.2;
	if (env->p->zoom > 100 && env->p->zoom <= 1000)
		i = 0.02;
	if (env->p->zoom > 1000 && env->p->zoom <= 10000)
		i = 0.002;
	if (env->p->zoom > 10000 && env->p->zoom <= 100000)
		i = 0.0002;
	if (env->p->zoom > 100000)
		i = 0.00002;
	i *= 4;
	return (i);
}

void			moove(int keycode, t_env *env)
{
	double	i;

	i = modify_moove(env);
	if (keycode == LEFT)
		env->p->x1 += i;
	else if (keycode == RIGHT)
		env->p->x1 -= i;
	else if (keycode == DOWN)
		env->p->y1 += i;
	else if (keycode == UP)
		env->p->y1 -= i;
}

static void		board_zoom(int keycode, t_env *env)
{
	env->p->x_real = (env->p->x / env->p->zoom) + env->p->x1;
	env->p->y_real = (env->p->y / env->p->zoom) + env->p->y1;
	if (keycode == ZOOMUP)
		env->p->zoom *= 1.1;
	if (keycode == ZOOMDOWN)
		env->p->zoom /= 1.1;
	env->p->x1 = env->p->x_real - (env->p->x / env->p->zoom);
	env->p->y1 = env->p->y_real - (env->p->y / env->p->zoom);
}

static void 	change_fractals(int keycode, t_env *env)
{
	static int	i;
	static char	*fracts[] = {"julia", "mandelbrot", "celtic", "test", "sword",
	 "tricorn", "chameleon", "bship"};
	if (keycode == Q && i > 0)
		env->name = fracts[--i];
	else if (keycode == Q && i == 0)
		env->name = fracts[i = 7];
	else if (keycode == W && i < 7)
		env->name = fracts[++i];
	else
		env->name = fracts[i = 0];
	free(env->p);
	if (!ft_strcmp(env->name, "julia") || !ft_strcmp(env->name, "sword") || \
		!ft_strcmp(env->name, "chameleon") || !ft_strcmp(env->name, "test"))
		env->p = init_julia();
	else if (!(ft_strcmp(env->name, "mandelbrot")) || \
		!ft_strcmp(env->name, "bship") || !ft_strcmp(env->name, "tricorn") \
		|| !ft_strcmp(env->name, "celtic"))
		env->p = init_mandelbrot();
}

int				key_funct(int keycode, t_env *env)
{
	if (env->mlx == NULL)
		return (0);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == MORE_ITER || keycode == LESS_ITER)
		iter(keycode, env);
	if (keycode == MORE_COLOR || keycode == LESS_COLOR)
		color(keycode, env);
	if (keycode == LEFT || keycode == RIGHT || keycode == UP\
			|| keycode == DOWN)
		moove(keycode, env);
	if (keycode == T1 || keycode == T2 || keycode == T3 || keycode == T4 || \
			keycode == T5)
		theme(keycode, env);
	if (keycode == ORIGIN)
		origin(keycode, env);
	if (keycode == ZOOMUP || keycode == ZOOMDOWN)
		board_zoom(keycode, env);
	if (keycode == Q || keycode == W)
		change_fractals(keycode, env);
	select_fractals(env);
	return (0);
}

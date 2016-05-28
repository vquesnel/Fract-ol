/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_fractals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:53:15 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/29 01:08:40 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_win(t_env *e)
{
	free(e);
	exit(EXIT_SUCCESS);
}

void		select_fractals(t_env *env)
{
	if (ft_strcmp(env->name, "julia") == 0)
		draw_julia(env);
	if (ft_strcmp(env->name, "mandelbrot") == 0)
		draw_mandelbrot(env);
	if (ft_strcmp(env->name, "bship") == 0)
		draw_bship(env);
	if (ft_strcmp(env->name, "sword") == 0)
		draw_sword(env);
	if (ft_strcmp(env->name, "chameleon") == 0)
		draw_chameleon(env);
	if (ft_strcmp(env->name, "tricorn") == 0)
		draw_tricorn(env);
	if (ft_strcmp(env->name, "celtic") == 0)
		draw_celtic(env);
	if (ft_strcmp(env->name, "test") == 0)
		draw_test(env);
	mlx_clear_window(env->mlx, env->win);
	menu(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_hook(env->win, 6, 1 << 8, motion_juliaandco, env);
	mlx_hook(env->win, 2, 3, key_funct, env);
	mlx_hook(env->win, 17, 1L << 17, close_win, env);
	mlx_loop(env->mlx);
}

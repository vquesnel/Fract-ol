/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_fractals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:53:15 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/17 15:00:33 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		select_fractals(t_env *env)
{
	printf("color = %X\n", env->p->col);
	if (ft_strcmp(env->name, "julia") == 0)
		draw_julia(env);
	else if (ft_strcmp(env->name, "mandelbrot") == 0)
		draw_mandelbrot(env);
	else if (ft_strcmp(env->name, "bship") == 0)
		draw_bship(env);
	else if (ft_strcmp(env->name, "sword") == 0)
		draw_sword(env);
	else if (ft_strcmp(env->name, "chameleon") == 0)
		draw_chameleon(env);
	else if (ft_strcmp(env->name, "tricorn") == 0)
		draw_tricorn(env);
	mlx_clear_window(env->mlx, env->win);
	menu(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_hook(env->win, 6, 1 << 8, motion_juliaandco, env);
	mlx_hook(env->win, 2, 3, key_funct, env);
	mlx_loop(env->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_wings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:55:13 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/12 19:01:28 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	left_wing(t_env *env)
{
	int		x;
	int		y;

	x = 148;
	y = 646;
	while (x++ < 383)
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
	while (y++ < 781)
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
	x = 148;
	y = 646;
	while (y++ < 781)
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
	while (x++ < 383)
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
}

void	right_wing(t_env *env)
{
	int		x;
	int		y;

	x = 642;
	y = 646;
	while (x++ < 890)
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
	while (y++ < 781)
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
	x = 642;
	y = 646;
	while (y++ < 781)
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
	while (x++ < 890)
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
}

void	body(t_env *env)
{
	int		x;
	int		y;

	x = 384;
	y = 592;
	while (x++ <= 640)
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
	while (y++ <= 831)
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
	x = 384;
	y = 592;
	while (y++ <= 831)
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
	while (x++ <= 640)
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFF0000);
}

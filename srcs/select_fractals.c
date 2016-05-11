/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_fractals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:53:15 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/11 16:15:59 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		select_fractals(t_env *env)
{
	if (ft_strcmp(env->name, "julia") == 0)
		draw_julia(env);
	else if (ft_strcmp(env->name, "mandelbrot") == 0)
		draw_mandelbrot(env);
	else if (ft_strcmp(env->name, "bship") == 0)
		draw_bship(env);
	else
		ft_error("connard");
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_hook(env->win, 2, 3, key_funct, env);
	mlx_loop(env->mlx);
}

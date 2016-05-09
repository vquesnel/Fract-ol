/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 16:16:43 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/09 15:00:11 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_fract(t_env *env)
{
	if (!(ft_strcmp(env->name, "julia")))
	{
		init_julia(env);
		return (TRUE);
	}
	if (!(ft_strcmp(env->name, "mandelbrot")))
	{
		init_mandel(env);
		return (TRUE);
	}
	if (!(ft_strcmp(env->name, "sierpinski")))
	{
		init_sierpinski(env);
		return (TRUE);
	}
	if (!(ft_strcmp(env->name, "b_ship")))
	{
		init_burningship(env);
		return (TRUE);
	}
	else
		ft_error("usage: ./fractol [Mandelbrot, julia, ...]");
	return (FALSE);
}


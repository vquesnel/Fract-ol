/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 16:16:43 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/04 15:24:20 by vquesnel         ###   ########.fr       */
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
	if (!(ft_strcmp(env->name, "Mandelbrot")))
	{
		init_mandel(env);
		return (TRUE);
	}
	//	else if (!(ft_strcmp(str, "Modulo")))
	//		init_modul(env);
	else
		ft_error("usage: ./fractol [Mandelbrot, julia, ...]");
	return (FALSE);
}


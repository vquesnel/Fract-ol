/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:21:32 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/09 14:22:14 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int mousecode, t_env *env, t_param hook)
{
	if (mousecode == 5)
		hook.zoom += 20;
	if (mousecode == 4 && hook.zoom > 20)
		hook.zoom -= 20;
	env->param = new_param(hook);
//	mlx_destroy_image(env->mlx, env->img->img);
	init_fract(env);
}

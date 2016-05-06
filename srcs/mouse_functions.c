/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:21:32 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/06 17:57:54 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int mousecode, t_env *env, t_param hook)
{
	if (mousecode == 5)
		hook.zoom += 5;
	if (mousecode == 4 && hook.zoom > 5)
		hook.zoom -= 5;
	env->param = new_param(hook);
		mlx_clear_window(env->mlx, env->win);
	init_fract(env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:20:52 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/04 15:58:38 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_funct(int keycode, t_env *env)
{
	t_param		hook;

	if (env->mlx == NULL)
		return (0);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	hook.zoom = env->param->zoom;
	hook.iter = env->param->iter;
	if (keycode == MORE_ITER || keycode == LESS_ITER)
		iter(keycode, env, hook);
	return (0);
}

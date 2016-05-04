/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 15:46:01 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/04 16:07:44 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_funct(int button, int x, int y, t_env *env)
{
	t_param		hook;

	hook.zoom = env->param->zoom;
	hook.iter = env->param->iter;
	if (x >= 0 && x < X_SIZE && y >= 0 && y < Y_SIZE)
	{
		if (button == 5)
			hook.zoom *= 1.1;
		if (button == 4)
			hook.zoom /= 1.1;
	}
	env->param = new_param(hook);
	init_fract(env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 15:46:01 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/06 17:42:11 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_funct(int button, int x, int y, t_env *env)
{
	t_param		hook;

	hook.zoom = env->param->zoom;
	hook.iter = env->param->iter;
	hook.x_default = env->param->x_default;
	hook.y_default = env->param->y_default;
	hook.color = env->param->color;
	hook.c_r = env->param->c_r;
	hook.c_i = env->param->c_i;
	(void)x;
	(void)y;
	if (button == 5 || button == 4)
		zoom(button, env, hook);
	return (0);
}

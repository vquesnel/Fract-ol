/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 15:46:01 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/05 16:24:55 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_funct(int button, int x, int y, t_env *env)
{
	t_param		hook;

	hook.zoom = env->param->zoom;
	(void)x;
	(void)y;
	if (button == 5 || button == 4)
		zoom(button, env, hook);
	return (0);
}

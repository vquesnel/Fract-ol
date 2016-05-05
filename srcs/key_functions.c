/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:28:38 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/05 15:28:56 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter(int keycode, t_env *env, t_param hook)
{
	if (keycode == MORE_ITER)
		hook.iter++;
	if (keycode == LESS_ITER)
		hook.iter--;
	env->param = new_param(hook);
	init_fract(env);
}

void	color(int keycode, t_env *env, t_param hook)
{
	if (keycode == MORE_COLOR && hook.color < 8421504)
		hook.color *= 255;
	if (keycode == LESS_COLOR && hook.color > 255)
		hook.color /= 255;
	printf("color = %d\n", hook.color);
	env->param = new_param(hook);
	init_fract(env);
}

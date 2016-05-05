/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:28:38 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/05 16:11:31 by vquesnel         ###   ########.fr       */
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
	env->param = new_param(hook);
	init_fract(env);
}

void	parameter(int keycode, t_env *env, t_param hook)
{
	if (keycode == 18 && hook.c_r < 1.25)
		hook.c_r += 0.1;
	if (keycode == 19 && hook.c_r > -1.249)
		hook.c_r -= 0.1;
	if (keycode == 20 && hook.c_i < 1.249)
		hook.c_i += 0.01;
	if (keycode == 21 && hook.c_i > -1.249)
		hook.c_i -= 0.01;
	env->param = new_param(hook);
	init_fract(env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:20:52 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/12 10:46:14 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_funct(int keycode, t_env *env)
{
	if (env->mlx == NULL)
		return (0);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == MORE_ITER || keycode == LESS_ITER)
		iter(keycode, env);
	if (keycode == MORE_COLOR || keycode == LESS_COLOR)
		color(keycode, env);
	if (keycode == LEFT || keycode == RIGHT || keycode == UP\
	|| keycode == DOWN)
		moove(keycode, env);
	if ( keycode == T1 || keycode == T2 || keycode == T3 || keycode == T4 || \
	keycode == T5)
		theme(keycode, env);
	if (keycode == ORIGIN)
		origin(keycode, env);
	if (keycode == SPACE)
		menu(env);
	return (0);
}

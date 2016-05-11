/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:28:38 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/12 00:35:09 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter(int keycode, t_env *env)
{
	if (keycode == MORE_ITER)
		env->p->iter++;
	if (keycode == LESS_ITER && env->p->iter > 1)
		env->p->iter--;
}

void	theme(int keycode, t_env *env)
{
	if (keycode == T1)
		env->p->col = 0xFFD7A5;
	if (keycode == T2)
		env->p->col = 0x00FF43;
	if (keycode == T3)
		env->p->col = 0x090893;
	if (keycode == T4)
		env->p->col = 0xFF0036;
	if (keycode == T5)
		env->p->col = 0x0096DF;
}

void	color(int keycode, t_env *env)
{
	if (keycode == MORE_COLOR && env->p->col < 2147483391)
		env->p->col += 2030;
	if (keycode == LESS_COLOR && env->p->col > 256)
		env->p->col -= 2030;
}

void		moove(int keycode, t_env *env)
{
	if (keycode == LEFT)
		env->p->x1 += 0.0001;
	else if (keycode == RIGHT)
		env->p->x1 -= 0.0001;
	else if (keycode == DOWN)
		env->p->y1 += 0.0001;
	else if (keycode == UP)
		env->p->y1 -= 0.0001;
}

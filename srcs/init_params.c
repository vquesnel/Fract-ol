/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:06:17 by vquesnel          #+#    #+#             */
/*   Updated: 2018/02/05 17:15:21 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_param		*init_julia(void)
{
	t_param *p;

	if (!(p = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	p->iter = 75;
	p->motion = 0;
	p->x1 = -1.95;
	p->y1 = -1.95;
	p->zoom = 200;
	p->c_r = 0.285;
	p->c_i = 0.01;
	p->col = 0xFFFFFF;
	p->x_real = X_SIZE / 2;
	p->y_real = Y_SIZE / 2;
	p->x = X_SIZE / 2;
	p->y = Y_SIZE / 2;
	return (p);
}

t_param		*init_mandelbrot(void)
{
	t_param *p;

	if (!(p = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	p->iter = 75;
	p->motion = 0;
	p->x1 = -2.02;
	p->x2 = 0.6;
	p->y1 = -2.02;
	p->y2 = 1.2;
	p->zoom = 200;
	p->col = 0xef0b0b;
	p->x = 0;
	p->y = 0;
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:06:17 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/11 17:44:39 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_param		*init_julia(void)
{
	t_param *p;

	if (!(p = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	p->iter = 100;
	p->motion = 0;
	p->x1 = -1.25;
	p->y1 = -1.25;
	p->zoom = 300;
	p->c_r = 0.285;
	p->c_i = 0.01;
	p->color = 0xef0b0b;
	return (p);
}

t_param		*init_mandelbrot(void)
{
	t_param *p;

	if (!(p = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	p->iter = 100;
	p->motion = 0;
	p->x1 = -2.1;
	p->x2 = 0.6;
	p->y1 = -1.2;
	p->y2 = 1.2;
	p->zoom = 300;
	p->color = 0xef0b0b;
	return (p);
}

t_param		*init_bship(void)
{
	t_param *p;

	if (!(p = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	p->iter = 100;
	p->motion = 0;
	p->x1 = -3;
	p->x2 = 2.5;
	p->y1 = -2;
	p->y2 = 3;
	p->zoom = 150;
	p->color = 0xef0b0b;
	return (p);
}

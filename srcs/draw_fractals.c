/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:19:17 by vquesnel          #+#    #+#             */
/*   Updated: 2018/02/05 13:57:51 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_mandelbrot(t_threads *t)
{
	int i;
	int x;

	while (++t->begin <= t->end && (x = -1))
		while (++x < X_SIZE && (i = -1))
		{
			PARAM->c_r = x / PARAM->zoom + PARAM->x1;
			PARAM->c_i = t->begin / PARAM->zoom + PARAM->y1;
			PARAM->z_r = 0;
			PARAM->z_i = 0;
			while (PARAM->z_r * PARAM->z_r + PARAM->z_i * PARAM->z_i
				< 4 && ++i < PARAM->iter)
			{
				PARAM->tmp = PARAM->z_r;
				PARAM->z_r = PARAM->z_r * PARAM->z_r - PARAM->z_i *
					PARAM->z_i + PARAM->c_r;
				PARAM->z_i = 2 * PARAM->z_i * PARAM->tmp + PARAM->c_i;
			}
			if (i == PARAM->iter)
				pixel_to_image(t->e, x, t->begin, 0);
			else
				pixel_to_image(t->e, x, t->begin, PARAM->col * i / PARAM->iter);
		}
	pthread_exit(NULL);
}

void		draw_bship(t_threads *t)
{
	int i;
	int x;

	while (++t->begin <= t->end && (x = -1))
		while (++x < X_SIZE && (i = -1))
		{
			PARAM->c_r = x / PARAM->zoom + PARAM->x1;
			PARAM->c_i = t->begin / PARAM->zoom + PARAM->y1;
			PARAM->z_r = 0;
			PARAM->z_i = 0;
			while (PARAM->z_r * PARAM->z_r + PARAM->z_i * PARAM->z_i
				< 4 && ++i < PARAM->iter)
			{
				PARAM->tmp = PARAM->z_r;
				PARAM->z_r = fabs(PARAM->z_r * PARAM->z_r - PARAM->z_i *
						PARAM->z_i + PARAM->c_r);
				PARAM->z_i = fabs(2 * PARAM->z_i * PARAM->tmp + PARAM->c_i);
			}
			if (i == PARAM->iter)
				pixel_to_image(t->e, x, t->begin, 0);
			else
				pixel_to_image(t->e, x, t->begin, PARAM->col * i / PARAM->iter);
		}
	pthread_exit(NULL);
}

void		draw_tricorn(t_threads *t)
{
	int i;
	int x;

	while (++t->begin <= t->end && (x = -1))
		while (++x < X_SIZE && (i = -1))
		{
			PARAM->c_r = x / PARAM->zoom + PARAM->x1;
			PARAM->c_i = t->begin / PARAM->zoom + PARAM->y1;
			PARAM->z_r = 0;
			PARAM->z_i = 0;
			while (PARAM->z_r * PARAM->z_r + PARAM->z_i * PARAM->z_i
				< 4 && ++i < PARAM->iter)
			{
				PARAM->tmp = PARAM->z_r;
				PARAM->z_r = PARAM->z_r * PARAM->z_r - PARAM->z_i * PARAM->z_i
					+ PARAM->c_r;
				PARAM->z_i = -2 * PARAM->z_i * PARAM->tmp + PARAM->c_i;
			}
			if (i == PARAM->iter)
				pixel_to_image(t->e, x, t->begin, 0);
			else
				pixel_to_image(t->e, x, t->begin, PARAM->col * i / PARAM->iter);
		}
	pthread_exit(NULL);
}

void		draw_celtic(t_threads *t)
{
	int i;
	int x;

	while (++t->begin <= t->end && (x = -1))
		while (++x < X_SIZE && (i = -1))
		{
			PARAM->c_r = x / PARAM->zoom + PARAM->x1;
			PARAM->c_i = t->begin / PARAM->zoom + PARAM->y1;
			PARAM->z_r = 0;
			PARAM->z_i = 0;
			while ((PARAM->z_r * PARAM->z_r + PARAM->z_i * PARAM->z_i)
			< 4 && ++i < PARAM->iter)
			{
				PARAM->tmp = PARAM->z_r;
				PARAM->z_r = fabs(PARAM->z_r * PARAM->z_r - PARAM->z_i *
					PARAM->z_i) + PARAM->c_r;
				PARAM->z_i = 2 * PARAM->z_i * PARAM->tmp + PARAM->c_i;
			}
			if (i == PARAM->iter)
				pixel_to_image(t->e, x, t->begin, 0);
			else
				pixel_to_image(t->e, x, t->begin, PARAM->col * i / PARAM->iter);
		}
	pthread_exit(NULL);
}

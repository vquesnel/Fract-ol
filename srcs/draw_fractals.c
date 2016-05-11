/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:19:17 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/11 17:50:09 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_julia(t_env *e)
{
	int		i;
	double	tmp;
	int		x;
	int		y;

	x = 0;
	while (x < X_SIZE)
	{
		y = 0;
		while (y < Y_SIZE)
		{
			e->p->z_r = x / e->p->zoom + e->p->x1;
			e->p->z_i = y / e->p->zoom + e->p->y1;
			i = 0;
			while (e->p->z_r * e->p->z_r + e->p->z_i * e->p->z_i < 4 && \
					i < e->p->iter)
			{
				tmp = e->p->z_r;
				e->p->z_r = e->p->z_r * e->p->z_r - e->p->z_i * e->p->z_i + \
							e->p->c_r;
				e->p->z_i = 2 * e->p->z_i * tmp + e->p->c_i;
				i++;
			}
			if (i == e->p->iter)
				mlx_put_pixel_to_image(e, x, y, 0);
			else
				mlx_put_pixel_to_image(e, x, y, i * e->p->color / e->p->iter / 25);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
}

void		draw_mandelbrot(t_env *e)
{
	int		i;
	double	tmp;
	int		x;
	int		y;

	x = 0;
	while (x < X_SIZE)
	{
		y = 0;
		while (y < Y_SIZE)
		{
			e->p->c_r = x / e->p->zoom + e->p->x1;
			e->p->c_i = y / e->p->zoom + e->p->y1;
			e->p->z_r = 0;
			e->p->z_i = 0;
			i = 0;
			while ((e->p->z_r * e->p->z_r + e->p->z_i * e->p->z_i) < 4 && i < e->p->iter)
			{
				tmp = e->p->z_r;
				e->p->z_r = e->p->z_r * e->p->z_r - e->p->z_i * e->p->z_i + e->p->c_r;
				e->p->z_i = 2 * e->p->z_i * tmp + e->p->c_i;
				i++;
			}
			if (i == e->p->iter)
				mlx_put_pixel_to_image(e, x, y, 0);
			else
				mlx_put_pixel_to_image(e, x, y, i * e->p->color / e->p->iter / 2);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
}

void		draw_bship(t_env *e)
{
	int		i;
	double	tmp;
	int		x;
	int		y;

	x = 0;
	while (x < X_SIZE)
	{
		y = 0;
		while (y < Y_SIZE )
		{
			e->p->c_r = x / e->p->zoom + e->p->x1;
			e->p->c_i = y / e->p->zoom + e->p->y1;
			e->p->z_r = 0;
			e->p->z_i = 0;
			i = 0;
			while (e->p->z_r * e->p->z_r + e->p->z_i * e->p->z_i < 4 && i < e->p->iter)
			{
				tmp = e->p->z_r;
				e->p->z_r = fabs(e->p->z_r * e->p->z_r - e->p->z_i * e->p->z_i + e->p->c_r);
				e->p->z_i = fabs(2 * e->p->z_i * tmp + e->p->c_i);
				i++;
			}
			if (i == e->p->iter)
				mlx_put_pixel_to_image(e, x, y, 0);
			else
				mlx_put_pixel_to_image(e, x, y, i * e->p->color / e->p->iter / 2);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
}

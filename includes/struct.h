/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:53:26 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/12 10:46:30 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_img;

typedef struct	s_param
{
	int			iter;
	int			motion;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			col;
	int			x;
	int			y;
	double		tmp;
	int			i;
}				t_param;

typedef struct	s_env
{
	char		*name;
	void		*mlx;
	void		*win;
	t_img		*img;
	t_param		*p;
}				t_env;

#endif

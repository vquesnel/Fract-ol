/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 16:08:50 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/05 15:47:19 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_img;

typedef struct		s_pram
{
	int				iter;
	int				zoom;
	float			x_default;
	float			y_default;
	int				color;
	long double		c_r;
	long double		c_i;
}					t_param;

typedef struct		s_env
{
	char			*name;
	void			*mlx;
	void			*win;
	t_img			*img;
	t_param			*param;
}					t_env;

typedef struct		s_affine
{
	int				x;
	int				y;
	float			coef;
	float			cst;
}					t_affine;

#endif

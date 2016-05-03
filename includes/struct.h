/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 16:08:50 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/03 16:14:27 by vquesnel         ###   ########.fr       */
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

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
}					t_env;

typedef struct		s_affine
{
	int				x;
	int				y;
	float			coef;
	float			cst;
}					t_affine;

#endif

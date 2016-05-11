/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:55:26 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/11 17:09:11 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include "struct.h"
# include "define.h"
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>

t_img	*init_img(t_env *env);
t_env	*init_env(char *str);
void	select_fractals(t_env *env);
t_param	*init_mandelbrot(void);
t_param	*init_julia(void);
t_param	*init_bship(void);
void	mlx_put_pixel_to_image(t_env *env, int x, int y, int color);
void	draw_julia(t_env *env);
void	draw_mandelbrot(t_env *env);
void	draw_bship(t_env *env);

int		mouse_hook(int button, int x, int y, t_env *env);

int		key_funct(int keycode, t_env *env);
void	moove(int keycode, t_env *env);
void	color(int keycode, t_env *env);
void	iter(int keycode, t_env *env);
void	theme(int keycode, t_env *env);

#endif

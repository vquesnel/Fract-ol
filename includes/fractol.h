/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:16:55 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/06 17:52:28 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include "struct.h"
# include "libft.h"
# include "mlx.h"
# include "define.h"
# include <stdio.h>

t_img	*init_img(t_env *env);
t_env	*init_env(char *str);
int		init_fract(t_env *env);
void	init_mandel(t_env *env);
void	init_julia(t_env *env);
void	init_sierpinski(t_env *env);
void	mlx_put_pixel_to_image(t_env *env, int x, int y, int color);
int		key_funct(int keycode, t_env *env);
int		mouse_funct(int mousecode, int x, int y, t_env *env);
t_param	*init_param(int zoom, int iter);
t_param	*new_param(t_param hook);
void	iter(int keycode, t_env *env, t_param hook);
void	color(int keycode, t_env *env, t_param hook);
void	parameter(int keycode, t_env *env, t_param hook);
void	zoom(int mousecode, t_env *env, t_param hook);
void		moove(int keycode, t_env *env, t_param hook);

#endif

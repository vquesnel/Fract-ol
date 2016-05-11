/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:55:26 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/12 00:40:51 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include "struct.h"
# include "define.h"
# include "libft.h"
# include "mlx.h"
# include <math.h>

/*
** INIT_LIST HANDLING
*/

t_img	*init_img(t_env *env);
t_env	*init_env(char *str);
t_param	*init_mandelbrot(void);
t_param	*init_julia(void);
t_param	*init_bship(void);

/*
** IMAGE HANDLING
*/

void	pixel_to_image(t_env *env, int x, int y, int color);
void	set_pixel_to_image(t_env *env);

/*
** DRAWING FUNCTIONS
*/

void	select_fractals(t_env *env);
void	draw_mandelbrot(t_env *env);
void	draw_julia(t_env *env);
void	draw_bship(t_env *env);
void	draw_sword(t_env *e);
void	draw_chameleon(t_env *e);
void	draw_tricorn(t_env *e);

/*
** MOUSE HOOK HANDLING
*/

int		mouse_hook(int button, int x, int y, t_env *env);
int		motion_juliaandco(int x, int y, t_env *env);

/*
** KEY HOOK HANDLING
*/

int		key_funct(int keycode, t_env *env);
void	moove(int keycode, t_env *env);
void	color(int keycode, t_env *env);
void	iter(int keycode, t_env *env);
void	theme(int keycode, t_env *env);

#endif

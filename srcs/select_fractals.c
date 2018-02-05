/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_fractals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:53:15 by vquesnel          #+#    #+#             */
/*   Updated: 2018/02/05 16:43:39 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		select_fractals(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_clear_window(env->mlx, env->win);
	env->img = init_img(env);
	ft_print_threads(env);
	menu(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	return (0);
}

void	choose_fracals(t_env *env, pthread_t *t, t_threads *o, int i)
{
	if (!ft_strcmp(env->name, "julia"))
		pthread_create(&t[i], NULL, (void *)draw_julia, &o[i]);
	else if (!ft_strcmp(env->name, "mandelbrot"))
		pthread_create(&t[i], NULL, (void *)draw_mandelbrot, &o[i]);
	else if (!ft_strcmp(env->name, "bship"))
		pthread_create(&t[i], NULL, (void *)draw_bship, &o[i]);
	else if (!ft_strcmp(env->name, "sword"))
		pthread_create(&t[i], NULL, (void *)draw_sword, &o[i]);
	else if (!ft_strcmp(env->name, "chameleon"))
		pthread_create(&t[i], NULL, (void *)draw_chameleon, &o[i]);
	else if (!ft_strcmp(env->name, "tricorn"))
		pthread_create(&t[i], NULL, (void *)draw_tricorn, &o[i]);
	else if (!ft_strcmp(env->name, "celtic"))
		pthread_create(&t[i], NULL, (void *)draw_celtic, &o[i]);
	else if (!ft_strcmp(env->name, "test"))
		pthread_create(&t[i], NULL, (void *)draw_test, &o[i]);
}

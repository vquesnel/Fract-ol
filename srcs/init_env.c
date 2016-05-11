/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:03:50 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/11 14:59:39 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	*new_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->name = NULL;
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	env->p = NULL;
	return (env);
}

t_env	*init_env(char *str)
{
	t_env	*env;

	if (!(env = new_env()))
		return (NULL);
	env->name = str;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, X_SIZE, Y_SIZE, env->name);
	env->img = init_img(env);
	if (!(ft_strcmp(env->name, "julia")))
			env->p = init_julia();
	else if (!(ft_strcmp(env->name, "mandelbrot")))
			env->p = init_mandelbrot();
	else if (!(ft_strcmp(env->name, "bship")))
		env->p = init_bship();
	return (env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:03:50 by vquesnel          #+#    #+#             */
/*   Updated: 2018/02/05 17:06:46 by vquesnel         ###   ########.fr       */
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
	env->win = mlx_new_window(env->mlx, X_SIZE + 250, Y_SIZE, env->name);
	env->img = init_img(env);
	if (!ft_strcmp(env->name, "julia") || !ft_strcmp(env->name, "sword") || \
			!ft_strcmp(env->name, "chameleon") || !ft_strcmp(env->name, "test"))
		env->p = init_julia();
	else if (!(ft_strcmp(env->name, "mandelbrot")) || \
			!ft_strcmp(env->name, "bship") || !ft_strcmp(env->name, "tricorn") \
			|| !ft_strcmp(env->name, "celtic"))
		env->p = init_mandelbrot();
	return (env);
}

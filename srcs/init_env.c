/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:03:50 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/03 16:14:56 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	*new_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	return (env);
}

t_env	*init_env(void)
{
	t_env	*env;

	if (!(env = new_env()))
		return (NULL);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 1024, 850, "Vquesnel's Fract'ol");
	env->img = init_img(env);
	return (env);
}

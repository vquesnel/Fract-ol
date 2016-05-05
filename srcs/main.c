/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:59:38 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/05 16:10:34 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
	{
		ft_putstr("Usage: ./fractol [julia/mandelbrot/....]\n");
		return (0);
	}
	(void)av;
	env = init_env(av[1]);
	init_fract(env);
	mlx_mouse_hook(env->win, mouse_funct, env);
	mlx_hook(env->win, 2, 3, key_funct, env);
	mlx_loop(env->mlx);
	return (0);
}

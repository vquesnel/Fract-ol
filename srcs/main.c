/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:59:38 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/03 16:16:00 by vquesnel         ###   ########.fr       */
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
	env = init_env();
//	init_fract(av[1]);
//	mlx_hook(env->win, 6, 64, mouse_funct, &env);
	mlx_loop(env->mlx);
	return (0);
}

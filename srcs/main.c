/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:50:15 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/11 16:15:58 by vquesnel         ###   ########.fr       */
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
	env = init_env(av[1]);
	select_fractals(env);//	mlx_mouse_hook(env->win, mouse_hook, env);
	return (0);
}

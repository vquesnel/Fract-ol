/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:50:15 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/12 14:02:27 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		ft_error("Usage: ./fractol [julia/mandelbrot/bship/sword/tricorn/\
chameleon]");
	if (!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "mandelbrot") || \
			!ft_strcmp(av[1], "sword") || !ft_strcmp(av[1], "tricorn") || \
			!ft_strcmp(av[1], "bship") || !ft_strcmp(av[1], "chameleon"))
	{
		env = init_env(av[1]);
		select_fractals(env);
	}
	else
		ft_error("Usage: ./fractol [julia/mandelbrot/bship/sword/tricorn/ \
chameleon]");
	return (0);
}

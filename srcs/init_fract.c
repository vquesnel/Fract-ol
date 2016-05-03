/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 16:16:43 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/03 16:46:11 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_fract(char *str)
{
	if (!(ft_strcmp(str, "Julia")))
		init_julia();
	else if (!(ft_strcmp(str, "Mandelbrot")))
		init_mandel();
	else if (!(ft_strcmp(str, "Modulo")))
		init_modul();
}

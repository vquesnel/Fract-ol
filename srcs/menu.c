/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:55:05 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/12 19:10:25 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	signature(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 395, 612, 0xFFFF00, "XXXX                     ");
	mlx_string_put(mlx, win, 395, 622, 0xFFFF00, "X            XXXXX      ");
	mlx_string_put(mlx, win, 395, 632, 0xFFFF00, "XX             X     X   ");
	mlx_string_put(mlx, win, 395, 642, 0xFFFF00, "X XXX XXX  XXX X XXX X   ");
	mlx_string_put(mlx, win, 395, 652, 0xFFFF00, "X X   X X  X   X X X X   ");
	mlx_string_put(mlx, win, 395, 662, 0xFFFF00, "X X   XXXX XXX X XXX XXX ");
	mlx_string_put(mlx, win, 404, 682, 0xFFFF00, "X   X XXXX X   X X  X");
	mlx_string_put(mlx, win, 404, 692, 0xFFFF00, "XX XX X    XX  X X  X");
	mlx_string_put(mlx, win, 404, 702, 0xFFFF00, "X X X XXXX X X X X  X");
	mlx_string_put(mlx, win, 404, 712, 0xFFFF00, "X   X X    X  XX X  X");
	mlx_string_put(mlx, win, 404, 722, 0xFFFF00, "X   X XXXX X   X XXXX");
	mlx_string_put(mlx, win, 404, 746, 0xFF0000, "       vquesnel");
	mlx_string_put(mlx, win, 404, 762, 0xFF0000, "       kwiessle");
	mlx_string_put(mlx, win, 404, 791, 0xFFFF00, "zdteam 42        2016");
	mlx_string_put(mlx, win, 404, 791, 0xFF0000, "      @  school");
}

static void	options(void *mlx, void *win)
{
	signature(mlx, win);
	mlx_string_put(mlx, win, 700, 676, 0x00FF00, "moove    ");
	mlx_string_put(mlx, win, 700, 676, 0xFF0000, "         :  arrow");
	mlx_string_put(mlx, win, 700, 696, 0xFF0000, "         :  scroll");
	mlx_string_put(mlx, win, 700, 696, 0x00FF00, "zoom      ");
	mlx_string_put(mlx, win, 700, 716, 0xFF0000, "         :   esc");
	mlx_string_put(mlx, win, 700, 716, 0x00FF00, "exit     ");
	mlx_string_put(mlx, win, 700, 736, 0xFF0000, "         :   tild");
	mlx_string_put(mlx, win, 700, 736, 0x00FF00, "origin   ");
	mlx_string_put(mlx, win, 168, 676, 0xFF0000, "          :    a/s");
	mlx_string_put(mlx, win, 168, 676, 0x00FF00, "iter+/-    ");
	mlx_string_put(mlx, win, 168, 696, 0xFF0000, "          : leftclick");
	mlx_string_put(mlx, win, 168, 696, 0x00FF00, "parameters");
	mlx_string_put(mlx, win, 168, 716, 0xFF0000, "          :    +/-");
	mlx_string_put(mlx, win, 168, 716, 0x00FF00, "color+/- ");
	mlx_string_put(mlx, win, 168, 736, 0xFF0000, "          :   1 to 5");
	mlx_string_put(mlx, win, 168, 736, 0x00FF00, "themes   ");
}

int			menu(t_env *env)
{
	void	*mlx;
	void	*win;

	mlx = env->mlx;
	win = env->win;
	options(mlx, win);
	left_wing(env);
	right_wing(env);
	body(env);
	return (0);
}

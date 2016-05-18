/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:49:02 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/18 16:04:44 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	title(t_env *env)
{
	char	*title;
	int		i;

	i = 0;
	title = malloc(ft_strlen(env->name) + 1);
	while (env->name[i])
	{
		title[i] = ft_toupper(env->name[i]);
		i++;
	}
	title[i] = '\0';
	if (ft_strcmp(title, "JULIA") == 0)
		mlx_string_put(env->mlx, env->win, 865, 20, 0xC1500D, title);
	else
		mlx_string_put(env->mlx, env->win, 850, 20, 0xC1500D, title);
}

static void	commands(t_env *env)
{
	char	*iter;
	char	*zoom;

	iter = ft_itoa(env->p->iter);
	zoom = ft_itoa(env->p->zoom);
	mlx_string_put(env->mlx, env->win, 815, 70, 0x165AA4, "Moove   :  Arrows");
	mlx_string_put(env->mlx, env->win, 815, 110, 0x165AA4, "Iter +  :    s  ");
	mlx_string_put(env->mlx, env->win, 815, 150, 0x165AA4, "Iter -  :    a  ");
	mlx_string_put(env->mlx, env->win, 815, 190, 0x165AA4, "Reset   :   Tild ");
	mlx_string_put(env->mlx, env->win, 815, 230, 0x165AA4, "Themes  :  1 to 5");
	mlx_string_put(env->mlx, env->win, 815, 270, 0x165AA4, "Color + :    +  ");
	mlx_string_put(env->mlx, env->win, 815, 310, 0x165AA4, "Color - :    -  ");
	mlx_string_put(env->mlx, env->win, 815, 350, 0x165AA4, "Motion  :   Click");
	mlx_string_put(env->mlx, env->win, 813, 420, 0xC1500D, "    PARAMETERS   ");
	mlx_string_put(env->mlx, env->win, 815, 470, 0x165AA4, "Iter    :        ");
	mlx_string_put(env->mlx, env->win, 935, 470, 0x165AA4, iter);
	mlx_string_put(env->mlx, env->win, 815, 510, 0x165AA4, "Motion  :        ");
	if (env->p->motion == 0)
		mlx_string_put(env->mlx, env->win, 935, 510, 0x165AA4, "off");
	else
		mlx_string_put(env->mlx, env->win, 935, 510, 0x165AA4, "on");
	mlx_string_put(env->mlx, env->win, 815, 550, 0x165AA4, "Zoom    :        ");
	mlx_string_put(env->mlx, env->win, 935, 550, 0x165AA4, zoom);
}

void		menu(t_env *env)
{
	int		x;
	int		y;

	x = 800;
	y = 0;
	while (y <= Y_SIZE)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0x165AA4);
		y++;
	}
	title(env);
	commands(env);
}

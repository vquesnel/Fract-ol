/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:50:15 by vquesnel          #+#    #+#             */
/*   Updated: 2018/02/05 17:08:49 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_param	*ft_dup_param(t_param *p)
{
	t_param		*new;

	new = init_julia();
	new->iter = p->iter;
	new->motion = p->motion;
	new->x1 = p->x1;
	new->x2 = p->x2;
	new->y1 = p->y1;
	new->y1 = p->y1;
	new->y2 = p->y2;
	new->zoom = p->zoom;
	new->c_r = p->c_r;
	new->c_i = p->c_i;
	new->z_r = p->z_r;
	new->z_i = p->z_i;
	new->col = p->col;
	new->x = p->x;
	new->y = p->y;
	new->tmp = p->tmp;
	new->i = p->i;
	return (new);
}

static t_env	*ft_dup(t_env *env)
{
	t_env		*new;

	if ((new = malloc(sizeof(t_env))) == NULL)
		exit(0);
	new->name = env->name;
	new->mlx = env->mlx;
	new->win = env->win;
	new->img = env->img;
	new->img->img = env->img->img;
	new->img->data = env->img->data;
	new->img->bpp = env->img->bpp;
	new->img->sizeline = env->img->sizeline;
	new->img->endian = env->img->endian;
	new->p = ft_dup_param(env->p);
	return (new);
}

void			ft_print_threads(t_env *env)
{
	pthread_t	t[THREADS];
	int			i;
	t_threads	o[THREADS];

	i = -1;
	while (++i < THREADS)
	{
		o[i].e = ft_dup(env);
		o[i].begin = (X_SIZE / THREADS) * i;
		o[i].end = (X_SIZE / THREADS) * (i + 1);
		choose_fracals(env, t, o, i);
	}
	while (i--)
	{
		pthread_join(t[i], NULL);
		free(o[i].e->p);
		free(o[i].e);
	}
}

static int		close_win(t_env *e)
{
	free(e);
	exit(EXIT_SUCCESS);
}

int				main(int ac, char **av)
{
	t_env		*env;

	if (ac != 2)
		ft_error("Usage: ./fractol [julia/mandelbrot/bship/sword/tricorn/\
chameleon/test/celtic]");
	if (!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "mandelbrot") || \
			!ft_strcmp(av[1], "sword") || !ft_strcmp(av[1], "tricorn") || \
			!ft_strcmp(av[1], "bship") || !ft_strcmp(av[1], "chameleon") || \
			!ft_strcmp(av[1], "celtic") || !ft_strcmp(av[1], "test"))
	{
		env = init_env(av[1]);
		mlx_hook(env->win, 6, 1 << 8, motion_juliaandco, env);
		mlx_hook(env->win, 2, 3, key_funct, env);
		mlx_hook(env->win, 17, 1L << 17, close_win, env);
		mlx_mouse_hook(env->win, mouse_hook, env);
		mlx_loop_hook(env->mlx, select_fractals, env);
		mlx_loop(env->mlx);
	}
	else
		ft_error("Usage: ./fractol [julia/mandelbrot/bship/sword/tricorn/\
chameleon/celtic/test]");
	return (0);
}

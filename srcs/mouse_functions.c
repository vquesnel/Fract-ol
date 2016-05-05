/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:21:32 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/05 16:30:02 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int mousecode, t_env *env, t_param hook)
{
	if (mousecode == 5)
		hook.zoom *= 1.1;
	if (mousecode == 4)
		hook.zoom /= 1.1;
	env->param = new_param(hook);
	init_fract(env);
}

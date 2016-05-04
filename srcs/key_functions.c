/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:28:38 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/04 15:30:12 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter(int keycode, t_env *env, t_param hook)
{
	if (keycode == MORE_ITER)
		hook.iter++;
	if (keycode == LESS_ITER)
		hook.iter--;
	printf("iter == %d\n",hook.iter);
	env->param = new_param(hook);
	init_fract(env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:51:47 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/06 11:51:17 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_param		*init_param(int zoom, int iter)
{
	t_param *param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	param->iter = iter;
	param->zoom = zoom;
	param->x_default = 0;
	param->y_default = 0;
	param->color = 0xFAFAFA;
	param->c_r = 0.285;
	param->c_i = 0.01;
	return (param);
}

t_param		*new_param(t_param hook)
{
	t_param		*new;

	new = init_param(0, 0);
	new->iter = hook.iter;
	new->zoom = hook.zoom;
	new->x_default = hook.x_default;
	new->y_default = hook.y_default;
	new->color = hook.color;
	new->c_r = hook.c_r;
	new->c_i = hook.c_i;

	return (new);
}

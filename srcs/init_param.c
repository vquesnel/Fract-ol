/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:51:47 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/04 15:58:24 by vquesnel         ###   ########.fr       */
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
	return (param);
}

t_param		*new_param(t_param hook)
{
	t_param		*new;

	new = init_param(0, 0);
	new->iter = hook.iter;
	new->zoom = hook.zoom;
	return (new);
}

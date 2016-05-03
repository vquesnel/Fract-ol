/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:16:55 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/03 16:13:14 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include "struct.h"
# include "libft.h"
# include "mlx.h"
# include "define.h"

t_img	*init_img(t_env *env);
t_env	*init_env(void);

#endif

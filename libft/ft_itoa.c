/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:11:29 by vquesnel          #+#    #+#             */
/*   Updated: 2018/02/05 17:13:18 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_int_len(int n)
{
	int		q;
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		q = n % 10;
		n = n - q;
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		q;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_int_len(n);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len] = '\0';
	while (n > 0)
	{
		str[len-- - 1] = n % 10 + '0';
		q = n % 10;
		n = n - q;
		n = n / 10;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnbr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 09:18:19 by haouky            #+#    #+#             */
/*   Updated: 2024/01/07 14:03:56 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pnbr(int nb)
{
	long	n;
	char	c[12];
	int		i;
	int		a;

	n = nb;
	i = 0;
	a = 0;
	if (n == 0)
		c[i++] = '0';
	if (n < 0)
	{
		a += wrtc('-');
		n = -n;
	}
	while (n > 0)
	{
		c[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	a += i;
	while (i > 0)
		wrtc(c[--i]);
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:53:55 by mlamanti          #+#    #+#             */
/*   Updated: 2025/01/08 12:53:56 by mlamanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		i;
	char	num[12];
	int		out;

	out = 0;
	i = 0;
	if (nb == 0)
		return (write (1, "0", 1) - 1);
	else if (nb < 0)
	{
		out += write (1, "-", 1);
		if (nb == -2147483647)
			return (write (1, "2147483647", 10) - 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		num[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (--i >= 0)
		out += write (1, &num[i], 1);
	return (out - 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:17:04 by mlamanti          #+#    #+#             */
/*   Updated: 2025/01/08 15:17:05 by mlamanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	int		i;
	char	num[12];
	int		out;

	out = 0;
	i = 0;
	if (nb == 0)
		return (write (1, "0", 1) - 1);
	while (nb > 0)
	{
		num[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (--i >= 0)
		out += write (1, &num[i], 1);
	return (out - 1);
}


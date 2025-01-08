/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:55:34 by mlamanti          #+#    #+#             */
/*   Updated: 2025/01/08 12:55:36 by mlamanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n)
{
	char				*base;
	unsigned long		len;

	base = "0123456789abcdef";
	len = 0;
    if (n >= 16)
        len += ft_puthex(n / 16);
    len += write(1, &base[n % 16], 1);
    return (len);
}

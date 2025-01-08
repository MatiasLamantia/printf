/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:57:09 by mlamanti          #+#    #+#             */
/*   Updated: 2024/12/29 17:57:10 by mlamanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_options(char	s, va_list args, int *i)
{
	int	p;

	p = 0;
	if (s == 's')
		p += ft_putstr(va_arg(args, char *));
	else if (s == 'c')
		p += ft_putchar(va_arg(args, int));
	else if (s == 'p')
	{
		p += write(1, "0x", 2) - 1;
		p += ft_puthex(va_arg(args, unsigned long));
	}
	else if (s == 'd' || s == 'i')
		p += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		p += ft_putnbr_u(va_arg(args, unsigned int));
	else if (s == 'x')
		p += ft_puthex(va_arg(args, unsigned long)) - 1;
	else
		p += ft_putchar(s);
	(*i)++;
	return (p);
}
int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		p;
	int		printed;
	
	printed = 0;
	p = 0;
	if (!str)
		return (0);
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if(str[i] == '%')
		{
			printed += ft_printf_options(str[i + 1],args ,&i);
			i++;
			p++;
		}
		else if(str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (i - p + printed);
}

// int	main(void)
// {
// 	printf("res=%i\n",ft_printf(" %x ", 43));
// 	printf("res=%i",printf(" %x ", 43));
// }

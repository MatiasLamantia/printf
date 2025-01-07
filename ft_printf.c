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
	{
		p += ft_putstr(va_arg(args, char *));
		(*i)++;
	}
	if (s == 'c')
	{
		p += ft_putchar(va_arg(args, int));
		(*i)++;
	}
	else
		p += ft_putchar(s);

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
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (i - p);
}

int	main(void)
{
	// printf("%i\n",ft_printf("%s", "fifi"));
	// printf("%i",printf("%s", "fifi"));
	ft_printf("%s", "f");
	// printf("%s", "fifi");

}

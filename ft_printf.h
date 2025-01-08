/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:23:39 by mlamanti          #+#    #+#             */
/*   Updated: 2024/12/03 11:23:41 by mlamanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_putnbr_u(unsigned int nb);
int		ft_putnbr(int nb);
int		ft_printf(char const *str, ...);
int		ft_puthex(unsigned long n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
#endif
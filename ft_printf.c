/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:52:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/03/15 00:30:57 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_write(int total, int ret)
{
	if (total < 0 || ret < 0)
		return (-1);
	return (total + ret);
}

static int	parse_format(char spcfr, va_list args)
{
	if (spcfr == 'c')
		return (ft_print_c(va_arg(args, int)));
	else if (spcfr == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (spcfr == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long)));
	else if (spcfr == 'd' || spcfr == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (spcfr == 'u')
		return (ft_print_u(va_arg(args, unsigned int)));
	else if (spcfr == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (spcfr == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (spcfr == '%')
		return (ft_print_c('%'));
	else if (spcfr == 'a')
		return (write(1, "my awesome 42", 13));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	total = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			total = check_write(total, parse_format(format[++i], args));
		}
		else if (format[i] != '%')
			total = check_write(total, ft_print_c(format[i]));
		if (total < 0)
			break ;
		i++;
	}
	va_end(args);
	return (total);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmet <ahmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:52:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/03/13 14:52:00 by ahmet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_check_write - Yazilan karakter sayisini toplar.
** Herhangi bir write hatasi (-1) tespit edildiginde
** toplam degeri de -1 olarak isaretler.
** Boylece hata zincir boyunca yukari yayilir.
*/
static int	ft_check_write(int total, int ret)
{
	if (total < 0 || ret < 0)
		return (-1);
	return (total + ret);
}

/*
** ft_parse_format - Format belirleyicisine (specifier) gore
** uygun yazdirma fonksiyonunu cagirir.
** Desteklenen specifier'lar: c, s, p, d, i, u, x, X, %
*/
static int	ft_parse_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (ft_print_char('%'));
	return (-1);
}

/*
** ft_printf - printf fonksiyonunun 42 Norm uyumlu implementasyonu.
** Format stringini karakter karakter tarar. '%' goruldugunde
** bir sonraki karakteri specifier olarak ft_parse_format'a gonderir.
** Normal karakterleri dogrudan yazar.
** Basarili ise yazilan toplam karakter sayisini, hata durumunda -1 dondurur.
*/
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
			total = ft_check_write(total,
					ft_parse_format(format[++i], args));
		}
		else if (format[i] != '%')
			total = ft_check_write(total, ft_print_char(format[i]));
		if (total < 0)
			break ;
		i++;
	}
	va_end(args);
	return (total);
}

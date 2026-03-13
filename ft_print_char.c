/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmet <ahmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:52:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/03/13 14:52:00 by ahmet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_print_char - Tek bir karakteri standart cikisa (stdout) yazar.
** Basarili ise 1, write hatasi durumunda -1 dondurur.
*/
int	ft_print_char(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

/*
** ft_print_str - Bir stringi standart cikisa yazar.
** Eger string NULL ise, printf davranisina uygun olarak
** "(null)" stringini yazar.
** Basarili ise yazilan karakter sayisini, hata durumunda -1 dondurur.
*/
int	ft_print_str(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	if (write(1, s, len) == -1)
		return (-1);
	return (len);
}

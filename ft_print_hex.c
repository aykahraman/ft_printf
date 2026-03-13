/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmet <ahmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:52:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/03/13 14:52:00 by ahmet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_puthex_recursive - Sayiyi hexadecimal olarak recursive yazar.
** base parametresi kucuk harf (HEX_LOW) veya buyuk harf (HEX_UP)
** karakter dizisini belirler.
** len pointer ile hata kontrolu yapilir.
*/
static void	ft_puthex_recursive(unsigned long n, char *base, int *len)
{
	if (*len < 0)
		return ;
	if (n >= 16)
		ft_puthex_recursive(n / 16, base, len);
	if (*len < 0)
		return ;
	if (ft_print_char(base[n % 16]) == -1)
		*len = -1;
	else
		(*len)++;
}

/*
** ft_print_hex - unsigned int degeri hexadecimal formatta yazar.
** upper parametresi 1 ise buyuk harf (A-F), 0 ise kucuk harf (a-f).
** Basarili ise yazilan karakter sayisini, hata durumunda -1 dondurur.
*/
int	ft_print_hex(unsigned int n, int upper)
{
	int		len;
	char	*base;

	len = 0;
	if (upper)
		base = HEX_UP;
	else
		base = HEX_LOW;
	ft_puthex_recursive(n, base, &len);
	return (len);
}

/*
** ft_print_ptr - Pointer adresini "0x" oneki ile hexadecimal yazar.
** NULL pointer durumunda printf davranisina uygun olarak
** "(nil)" yazar.
** Basarili ise yazilan karakter sayisini, hata durumunda -1 dondurur.
*/
int	ft_print_ptr(unsigned long ptr)
{
	int	len;

	if (!ptr)
		return (ft_print_str("(nil)"));
	if (write(1, "0x", 2) == -1)
		return (-1);
	len = 2;
	ft_puthex_recursive(ptr, HEX_LOW, &len);
	return (len);
}

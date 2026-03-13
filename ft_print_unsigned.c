/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmet <ahmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:52:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/03/13 14:52:00 by ahmet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_putunbr_recursive - Isaretsiz (unsigned) sayiyi recursive olarak
** basamak basamak yazar.
** len pointer ile write hatasi kontrolu yapilir.
*/
static void	ft_putunbr_recursive(unsigned int n, int *len)
{
	if (*len < 0)
		return ;
	if (n >= 10)
		ft_putunbr_recursive(n / 10, len);
	if (*len < 0)
		return ;
	if (ft_print_char('0' + (n % 10)) == -1)
		*len = -1;
	else
		(*len)++;
}

/*
** ft_print_unsigned - Isaretsiz tam sayiyi ondalik (decimal) formatta yazar.
** Basarili ise yazilan karakter sayisini, hata durumunda -1 dondurur.
*/
int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	ft_putunbr_recursive(n, &len);
	return (len);
}

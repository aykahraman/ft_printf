/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmet <ahmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:52:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/03/13 14:52:00 by ahmet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_putnbr_recursive - Sayiyi recursive olarak basamak basamak yazar.
** long tipinde alinir, boylece INT_MIN tasma sorunu onlenir.
** len degeri pointer ile tasindigi icin, herhangi bir write hatasi
** aninda -1 olarak isaretlenir ve recursion sonlandirilir.
*/
static void	ft_putnbr_recursive(long n, int *len)
{
	if (*len < 0)
		return ;
	if (n >= 10)
		ft_putnbr_recursive(n / 10, len);
	if (*len < 0)
		return ;
	if (ft_print_char('0' + (n % 10)) == -1)
		*len = -1;
	else
		(*len)++;
}

/*
** ft_print_nbr - Isaret kontrolu yaparak tam sayiyi yazar.
** Negatif sayilarda once '-' yazilir, sayi pozitife cevrilir.
** INT_MIN icin long'a cast edildiginden tasma olmaz.
** Basarili ise yazilan karakter sayisini, hata durumunda -1 dondurur.
*/
int	ft_print_nbr(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		len++;
		nb = -nb;
	}
	ft_putnbr_recursive(nb, &len);
	return (len);
}

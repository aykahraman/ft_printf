/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:52:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/03/13 15:49:35 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putnbr_recursive(long n, int *len)
{
	if (*len < 0)
		return;
	if (n >= 10)
		ft_putnbr_recursive(n / 10, len);
	if (*len < 0)
		return;
	if (ft_print_char('0' + (n % 10)) == -1)
		*len = -1;
	else
		(*len)++;
}

int ft_print_nbr(int n)
{
	int len;
	long nb;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:52:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/03/13 15:49:35 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putunbr_recursive(unsigned int n, int *len)
{
	if (*len < 0)
		return;
	if (n >= 10)
		ft_putunbr_recursive(n / 10, len);
	if (*len < 0)
		return;
	if (ft_print_char('0' + (n % 10)) == -1)
		*len = -1;
	else
		(*len)++;
}

int ft_print_unsigned(unsigned int n)
{
	int len;

	len = 0;
	ft_putunbr_recursive(n, &len);
	return (len);
}

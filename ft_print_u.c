/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:52:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/03/15 00:15:48 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbru(unsigned int n, int *len)
{
	if (*len < 0)
		return ;
	if (n >= 10)
		ft_putnbru(n / 10, len);
	if (*len < 0)
		return ;
	if (ft_print_c('0' + (n % 10)) == -1)
		*len = -1;
	else
		(*len)++;
}

int	ft_print_u(unsigned int n)
{
	int	len;

	len = 0;
	ft_putnbru(n, &len);
	return (len);
}

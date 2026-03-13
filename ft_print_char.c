/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:52:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/03/13 15:49:22 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_char(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int ft_print_str(char *s)
{
	int len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	if (write(1, s, len) == -1)
		return (-1);
	return (len);
}

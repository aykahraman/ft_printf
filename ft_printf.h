/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahrama <akahrama@student.42.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:52:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/03/13 15:49:35 by akahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

#define HEX_LOW "0123456789abcdef"
#define HEX_UP "0123456789ABCDEF"

int ft_printf(const char *format, ...);

int ft_print_char(char c);
int ft_print_str(char *s);

int ft_print_nbr(int n);

int ft_print_unsigned(unsigned int n);

int ft_print_hex(unsigned int n, int upper);
int ft_print_ptr(unsigned long ptr);

#endif

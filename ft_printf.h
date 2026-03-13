/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmet <ahmet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:52:00 by ahmet             #+#    #+#             */
/*   Updated: 2026/03/13 14:52:00 by ahmet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* Hexadecimal karakter setleri (kucuk ve buyuk harf) */
# define HEX_LOW "0123456789abcdef"
# define HEX_UP  "0123456789ABCDEF"

/* Ana fonksiyon prototipi */
int	ft_printf(const char *format, ...);

/* Karakter ve string yazdirma */
int	ft_print_char(char c);
int	ft_print_str(char *s);

/* Sayisal deger yazdirma */
int	ft_print_nbr(int n);

/* Isaretsiz (unsigned) yazdirma */
int	ft_print_unsigned(unsigned int n);

/* Hexadecimal ve pointer yazdirma */
int	ft_print_hex(unsigned int n, int upper);
int	ft_print_ptr(unsigned long ptr);

#endif

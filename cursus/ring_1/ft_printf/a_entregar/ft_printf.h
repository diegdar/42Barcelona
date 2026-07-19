/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:58:40 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/09 17:00:56 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(char const *format, ...);
int		print_char(va_list *args);
int		print_str(va_list *args);
int		print_ptr(va_list *args);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		print_hex(va_list *args, const char type);
int		print_int(long long num);
size_t	ft_strlen(const char *s);

#endif

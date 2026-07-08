/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:58:40 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/08 18:14:04 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(char const *format, ...);
int	process_char(va_list *args);
int	process_str(va_list *args);
int	process_ptr(va_list *args);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int	process_hex(va_list *args, const char type);
int	process_percent();
#endif

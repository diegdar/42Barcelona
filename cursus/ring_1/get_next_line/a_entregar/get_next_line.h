/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:28:50 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/26 17:03:24 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096 
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, int c);
void	ft_copy_data(char *dest, const char *storage, const char *buffer);
char	*ft_strjoin_with_free(char const *buffer, char *storage);
char	*cut_excess(char *old_storage);

#endif

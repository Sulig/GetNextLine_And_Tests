/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:10:46 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/11 13:21:47 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_contains(const char *str, char in);
size_t	ft_strlen(const char *s);
char	*ft_free(char *to_free, char *tmp);
char	*ft_strdup(const char *s1, size_t len);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strtrim(char *str);
char	*ft_get_readed(int fd, char *store);
char	*get_next_line(int fd);

#endif

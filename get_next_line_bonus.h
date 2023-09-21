/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:04:46 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/21 16:07:51 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		gnl_contains(const char *str, char in);
size_t	gnl_strlen(const char *s);
size_t	gnl_cnt_tojump(const char *str);
char	*gnl_free(char *to_free, char *tmp);
char	*gnl_strlcpy(const char *s1, size_t len);
char	*gnl_join(char *s1, const char *s2);
char	*gnl_strcut(char *str);
char	*ft_get_readed(int fd, char *store);
char	*get_next_line(int fd);

#endif

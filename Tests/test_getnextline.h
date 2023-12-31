/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getnextline.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:16:27 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/21 17:07:26 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_GETNEXTLINE_H
# define TEST_GETNEXTLINE_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include "../GetNextLine/get_next_line.h"

# ifndef TBNS
#  define TBNS 0
# endif

size_t	len_tojump(const char *s);
size_t	my_strlen(const char *s);

int		contains(const char *str, char in);
int		look4ko(char *you, char *exp);
int		resume(int len, int *res);

void	sep(char c);
void	cc(char color);
#endif

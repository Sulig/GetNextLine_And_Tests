/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getnextline.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:16:27 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/08 18:42:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_GETNEXTLINE_H
# define TEST_GETNEXTLINE_H
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include "get_next_line.h"

int		look4ko(char *you, char *exp, char *fd, int line);
int		resume(int len, ...);

void	sep(char c);
void	cc(char color);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getnextline_main.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:21 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/11 11:52:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_getnextline.h"

static int	read_line(int fd, char *exp, int line, char *txt)
{
	char		*str;
	int			ret;

	str = get_next_line(fd);
	ret = look4ko(str, exp, txt, line);
	free(str);
	return (ret);
}

int	main(void)
{
	int		fd1, fd2, fd3, fd4, fd5, fd6;
	int		res[40];
	int		a;
	int		line;

	/**/
	printf("\033[1;34m\t     ~ Made by Sadoming ~\n");
	printf("\n\033[1;36m**///////////////////////////////////////////**\n");
	printf("**/          Testing Get Next Line          /**\n");
	printf("**///////////////////////////////////////////**\n\n");
	/**/
	fd1 = open("Tests/onln.txt", O_RDONLY);
	fd2 = open("Tests/twln.txt", O_RDONLY);
	fd3 = open("Tests/onechar.txt", O_RDONLY);
	fd4 = open("Tests/empty.txt", O_RDONLY);
	fd5 = open("Tests/mutnl.txt", O_RDONLY);
	fd6 = open("Tests/41_with_nl.txt", O_RDONLY);
	/**/
	cc('C');
	printf("|---------- - >\n");
	printf("|Buf Size |%i|\n", BUFFER_SIZE);
	printf("{~~~~~~~~~~~~~~~}\n\n");
	cc('w');
	/**/
	line = 0;
	a = 0;
	res[a++] = read_line(fd1, "one line\n", line, "onln.txt");
	res[a++] = read_line(fd2, "0123456789\n", line, "twln.txt");
	//res[a++] = read_line(fd1, NULL, 1, "onln.txt");
	res[a++] = read_line(fd2, "9876543210\n", 1, "twln.txt");
	res[a++] = read_line(fd3, "a", line, "onechar.txt");
	res[a++] = read_line(fd4, NULL, line, "empty.txt");
	while (a < 10)
		res[a++] = read_line(fd5, "\n", line++, "mutnl.txt");
	res[a++] = read_line(fd5, NULL, line, "mutnl.txt");
	res[a++] = read_line(fd6, "0123456789012345678901234567890123456789\n", 0, "41_with_nl.txt");
	res[a++] = read_line(fd6, "0", 1, "41_with_nl.txt");
	res[a++] = read_line(fd6, NULL, 2, "41_with_nl.txt");
	/**/
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);
	/**/
	sep(0);
	printf("\033[1;95m \n");
	return (0);
}

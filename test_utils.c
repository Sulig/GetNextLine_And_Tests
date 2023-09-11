/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:38:07 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/08 18:45:59 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_getnextline.h"

void	sep(char c)
{
	cc('y');
	if (!c || c == '\0')
		printf("~ ------------------------- ~\n");
	cc('w');
	printf("\n");
}

void	cc(char color)
{
	if (color == 'R' || color == 'r')
		printf("\033[1;91m");
	else if (color == 'G' || color == 'g')
		printf("\033[1;92m");
	else if (color == 'B' || color == 'b')
		printf("\033[1;34m");
	else if (color == 'Y' || color == 'y')
		printf("\033[1;93m");
	else if (color == 'W' || color == 'w')
		printf("\033[1;37m");
	else if (color == 'C' || color == 'c')
		printf("\033[1;36m");
}

int	look4ko(char *you, char *exp, char *fd, int line)
{
	int		ok;
	int		len;
	int		cnt;

	ok = 1;
	cnt = 0;
	cc('w');
	printf("Fd = |%s| ~ Line |%i|\t", fd, line);
	if ((!exp && you) || (exp && !you))
		ok = 0;
	len = ft_strlen(exp) + 1;
	while (cnt < len && ok != 0 && exp)
	{
		if (you[cnt] != exp[cnt])
			ok = 0;
		cnt++;
	}
	if (ok == 1)
	{
		cc('G');
		printf(" \t\t~ |OK| ~");
	}
	else
	{
		cc('R');
		printf(" \t\t~ |KO!| ~\n");
		printf("You don't return the expected! ->\n");
		printf("Org |Len = %zu|~|%s|\nYou |Len = %zu|~|%s|\n", ft_strlen(exp), exp, ft_strlen(you), you);
		printf("!! ----------------------------------- !!");
	}
	cc('W');
	printf("\n");
	return (ok);
}

int	resume(int len, ...)
{
	va_list	args;
	int		cnt;
	int		res;
	int		now;

	cnt = 0;
	res = 0;
	va_start(args, len);
	cc('C');
	printf("|---------- - >\n");
	printf("| Tests Resume: ");
	while (cnt < len)
	{
		now = va_arg(args, int);
		if (now == 1)
		{
			cc('G');
			printf("|OK| ");
			res++;
		}
		else if (now == 0)
		{
			cc('R');
			printf("|KO| ");
		}
		else
		{
			cc('Y');
			printf("|%i| ", now);
		}
		cnt++;
	}
	va_end(args);
	cc('C');
	printf("\n{~~~~~~~~~~~~~~~}");
	/**/
	if (res == len)
	{
		cc('g');
		printf("\t   |All tests are OK!|\n");
		return (1);
	}
	else
	{
		cc('y');
		printf("\t   |Revise your code|\n");
		return (0);
	}
}

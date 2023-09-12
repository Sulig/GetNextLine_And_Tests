/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_resume.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:35:16 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/12 12:38:03 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_getnextline.h"

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

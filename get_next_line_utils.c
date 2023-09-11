/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:06:49 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/11 13:46:13 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	if (s == NULL)
		return (0);
	while (s[cnt])
		cnt++;
	return (cnt);
}

int	ft_contains(const char *str, char in)
{
	size_t	cnt;

	cnt = 0;
	if (str == NULL)
		return (1);
	while (str[cnt])
	{
		if (str[cnt] == in)
			return (0);
		cnt++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	len;
	size_t	cnt;
	char	*join;

	if (!s1)
		return (ft_strdup(s2, ft_strlen(s2)));
	if (!s2)
		return (NULL);
	join = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!join)
		return (NULL);
	len = -1;
	cnt = 0;
	while (s1[++len])
		join[len] = s1[len];
	while (s2[cnt])
		join[len++] = s2[cnt++];
	join[len] = '\0';
	free(s1);
	return (join);
}

char	*ft_strdup(const char *s1, size_t len)
{
	char	*cpy;
	size_t	cnt;

	if (!s1 || len == 0)
		return (NULL);
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	cnt = 0;
	while (cnt < len)
	{
		cpy[cnt] = s1[cnt];
		cnt++;
	}
	cpy[len] = '\0';
	return (cpy);
}

char	*ft_strtrim(char *str)
{
	char	*trim;
	size_t	cnt;
	size_t	len;

	cnt = 0;
	len = 0;
	if (!str)
		return (NULL);
	while (str[cnt] && str[cnt] != '\n')
		cnt++;
	if (str[cnt] == '\n')
		cnt++;
	trim = malloc(sizeof(char) * ft_strlen(str + cnt) + 1);
	if (!trim)
		return (NULL);
	while (str[cnt])
		trim[len++] = str[cnt++];
	trim[len] = '\0';
	free(str);
	return (trim);
}

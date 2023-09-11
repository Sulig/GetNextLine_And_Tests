/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:06:43 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/11 13:46:09 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *to_free, char *tmp)
{
	if (to_free)
	{
		free(to_free);
		to_free = NULL;
	}
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

char	*ft_get_readed(int fd, char *store)
{
	int		lret;
	char	*tmp;

	lret = 1;
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (ft_contains(store, '\n') != 0)
	{
		lret = read(fd, tmp, BUFFER_SIZE);
		if (lret == -1)
			return (ft_free(store, tmp));
		if (lret == 0)
			break ;
		tmp[lret] = '\0';
		store = ft_strjoin(store, tmp);
	}
	free(tmp);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;
	size_t		cnt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = ft_get_readed(fd, store);
	if (!store)
		return (NULL);
	if (ft_strlen(store) == 0)
	{
		store = ft_free(store, 0);
		return (NULL);
	}
	cnt = 0;
	while (store[cnt] && store[cnt] != '\n')
		cnt++;
	if (store[cnt] == '\n')
		cnt++;
	line = ft_strdup(store, cnt);
	store = ft_strtrim(store);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:06:15 by sadoming          #+#    #+#             */
/*   Updated: 2023/09/13 14:16:50 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *to_free, char *tmp)
{
	if (to_free)
		free(to_free);
	to_free = NULL;
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

size_t	ft_cnt_tojump(const char *str)
{
	size_t	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] && str[cnt] != '\n')
		cnt++;
	if (str[cnt] == '\n')
		cnt++;
	return (cnt);
}

char	*ft_get_readed(int fd, char *store)
{
	int		btrd;
	char	*tmp;

	btrd = 1;
	tmp = malloc((BUFFER_SIZE) * sizeof(char) + 1);
	if (!tmp)
		return (ft_free(store, 0));
	while (btrd > 0 && (ft_contains(store, '\n') != 0))
	{
		btrd = read(fd, tmp, BUFFER_SIZE);
		if (btrd == -1)
			return (ft_free(store, tmp));
		if (btrd > 0)
		{
			tmp[btrd] = '\0';
			store = ft_strjoin(store, tmp);
			if (!store)
				return (ft_free(store, tmp));
		}
	}
	free(tmp);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store[4096];
	char		*line;
	size_t		cnt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = ft_get_readed(fd, store[fd]);
	if (!store[fd])
		return (ft_free(store[fd], 0));
	if (ft_strlen(store[fd]) == 0)
	{
		store[fd] = ft_free(store[fd], 0);
		return (NULL);
	}
	cnt = ft_cnt_tojump(store[fd]);
	line = ft_strdup(store[fd], cnt);
	if (!line)
	{
		store[fd] = ft_free(store[fd], 0);
		return (NULL);
	}
	store[fd] = ft_strtrim(store[fd]);
	return (line);
}

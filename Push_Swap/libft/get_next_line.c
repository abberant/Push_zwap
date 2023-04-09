/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:04:50 by aanouari          #+#    #+#             */
/*   Updated: 2023/03/25 14:00:59 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE < 1
		|| BUFFER_SIZE >= 2147483647 || read(fd, 0, 0) < 0)
		return (NULL);
	store = ft_readadd_to_store(fd, store);
	if (!store)
		return (NULL);
	line = ft_cull_line(store);
	store = ft_cull_extra(store);
	return (line);
}

char	*ft_readadd_to_store(int fd, char *store)
{
	int		depo;
	char	*scan;

	scan = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!scan)
		return (NULL);
	depo = 1;
	while (!ft_strchr(store, '\n') && depo)
	{
		depo = read(fd, scan, BUFFER_SIZE);
		if (depo == -1)
		{
			free(scan);
			return (NULL);
		}
		scan[depo] = '\0';
		store = ft_strjoin(store, scan);
	}
	free(scan);
	return (store);
}

char	*ft_cull_line(char *store)
{
	size_t	i;
	char	*line;

	if (!(*store))
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		line[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
		line[i] = store[i];
	return (line);
}

char	*ft_cull_extra(char *store)
{
	size_t	rid;
	size_t	keep;
	char	*remain;

	rid = 0;
	while (store[rid] && store[rid] != '\n')
		rid++;
	if (!store[rid])
	{
		free(store);
		return (NULL);
	}
	remain = ft_calloc(ft_strlen(store) - rid + 1, sizeof(char));
	if (!remain)
		return (NULL);
	rid++;
	keep = 0;
	while (store[rid])
		remain[keep++] = store[rid++];
	free(store);
	return (remain);
}

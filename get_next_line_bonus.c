/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:15:01 by joya              #+#    #+#             */
/*   Updated: 2023/12/26 13:15:37 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*clean_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (s[i] == '\0')
		return (NULL);
	if (ft_strchr(s, '\n') == NULL)
		line = ft_strdup(s);
	else
	{
		line = malloc(ft_strlen(s) - ft_strlen(ft_strchr(s, '\n')) + 1);
		if (line == NULL)
			return (NULL);
		while (s[i] != '\n')
		{
			line[i] = s[i];
			i++;
		}
		line[i] = s[i];
		line[i + 1] = '\0';
	}
	return (line);
}

char	*next_line(char *nlines)
{
	char	*line;

	if (nlines == NULL)
		return (NULL);
	if (ft_strchr(nlines, '\n') == NULL)
	{
		free (nlines);
		return (NULL);
	}
	line = ft_strdup(ft_strchr(nlines, '\n'));
	free (nlines);
	return (line);
}

char	*readfile(int fd, char *nlines)
{
	char	*aux;
	int		size;

	size = 1;
	aux = malloc(BUFFER_SIZE + 1);
	if (aux == NULL)
	{
		free (nlines);
		return (NULL);
	}
	while (nlines && size > 0 && ft_strchr(nlines, '\n') == NULL)
	{
		size = read(fd, aux, BUFFER_SIZE);
		if (size == -1)
		{
			free (nlines);
			free (aux);
			return (NULL);
		}
		aux[size] = '\0';
		nlines = ft_strjoin(nlines, aux);
	}
	free (aux);
	return (nlines);
}

char	*get_next_line(int fd)
{
	static char	*nlines[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (nlines[fd] == NULL)
	{
		nlines[fd] = malloc(sizeof(char) * 1);
		if (nlines[fd] == NULL)
			return (NULL);
		*nlines[fd] = '\0';
	}
	nlines[fd] = readfile(fd, nlines[fd]);
	if (nlines[fd] == NULL)
		return (NULL);
	line = clean_line(nlines[fd]);
	nlines[fd] = next_line(nlines[fd]);
	return (line);
}

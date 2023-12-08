/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:14:56 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/12/08 19:40:59 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_line(char * nline)
{
	char	*line;
	int		i;
	
	i = 0;
	if(!nline[i])
		return (NULL);
	if (ft_strchr(nline, '\n') == NULL)
		line = ft_strdup(nline);
	else
	{
		line = malloc(ft_strchr(nline, '\n') - nline + 1);  //ft_strlen(nline) - ft_strlen(ft_strchr(nline, '\n')) + 1
		if (line == NULL)
			return (NULL);
		while (nline[i] != '\n')
		{
			line[i] = nline[i];
			i++;
		}
		line[i] = nline[i];
		line[i + 1] = '\0';
	}
	return (line);
}


char	*next_line(char *nlines)
{
	char	*line;

	if (ft_strchr(nlines, '\n') == NULL)
	{
		free (nlines);
		return (NULL);
	}
	line = ft_strdup(ft_strchr(nlines, '\n'));
	free (nlines);
	return(line);
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
	while (size > 0 && ft_strchr(nlines, '\n') == NULL)  // a lo mejor hace falta decir tambien hasta que llegue al final de nlines
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
	static char	*nlines;
	char		*line;
 
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (nlines == NULL)
	{
		nlines = malloc(sizeof(char) * 1);
		if (nlines == NULL)
			return (NULL);
		nlines[0] = '\0';
	}
	nlines = readfile(fd, nlines);
	if (nlines == NULL)
		return (NULL);
	line = get_line(nlines);
	nlines = next_line(nlines);
	return (line);
}

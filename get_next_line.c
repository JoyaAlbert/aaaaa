/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:14:56 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/11/22 17:59:58 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *aux)
{
	int		i;
	char	*line;

	i = 0;
	while (aux[i] != '\n' && aux[i] != '\0')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (aux[i] != '\n' && aux[i] != '\0')
	{
		line[i] = aux[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*delete_first(char *aux)
{
	int		i;
	int		j;
	char	*nlines;

	j = 0;
	i = 0;
	while (aux[i] != '\n' && aux[i] != '\0')
		i++;
	nlines = malloc((int)ft_strlen(aux) - i);
	while (j < (int)ft_strlen(aux) - i)
	{
		nlines[j] = aux[j + i + 1];
		j++;
	}
	nlines[j] = '\0';
	return (nlines);
}

char	*readfile(int fd, int text)
{	
	int		a;
	char	*aux;
	int		size;

	size = 0;
	aux = malloc(BUFFER_SIZE);
	if (aux == NULL)
		return (NULL);
	while(size <= text)
	{
		a = read(fd, aux, BUFFER_SIZE);
		if (a == -1)
			return (NULL);
		size = a + size;
	}
	return (aux);
}

int	check(char *string)
{
	int i;

	i = 0;
	while (i < ft_strlen(string))
	{
		if (string[i] == '\n')
			return(1);
		if (string[i] == '\0')
			return (2);
			i++;
	}
	return (0);
}
char	*text(int fd, char *nlines, int size)
{
	char	aux[1024];
	char 	*buffer;

	buffer = readfile(fd, size);
	if (buffer == NULL)
	{
		free (buffer);
		return (NULL);
	}
	if (nlines == 0)
		ft_strlcpy(aux, buffer, ft_strlen(buffer));
	else
	{
		ft_strlcpy(aux, nlines, size);
		ft_strladd(aux, buffer, ft_strlen(buffer));		
	}
	while(check(aux) != 1)
	{
		buffer = readfile(fd, size);
		ft_strladd(aux, buffer, ft_strlen(buffer));
	}
	return(fill_line(ft_strlen(aux), aux));
}

char	*get_next_line(int fd)
{
	static char		*nlines;
	char			*line;
	char			*aux;
	int				size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (nlines == NULL)
		size = 0;
	else
		size = ft_strlen(nlines);
	aux = text(fd, nlines, size);
	if (aux == NULL)
	{
		free(aux);
		return (aux);
	}
	nlines = aux;
	line = next_line(aux);
	while (check(line) == 1)
		line = next_line(aux);
	nlines = delete_first(nlines);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:14:56 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/12/08 00:08:54 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (const char)c)
		i++;
	if (s[i] == (const char)c)
		return ((char *)s + i);
	return (NULL);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*total;
	unsigned int	i;
	unsigned int	size;
	unsigned int	size1;

	i = 0;
	size = ft_strlen(s1);
	size1 = ft_strlen(s2);
	total = (char *)malloc((size * sizeof(char)) + (size1 * sizeof(char)) + 1);
	if (total == NULL)
		return (NULL);
	while (i < size)
	{
		total[i] = s1[i];
		i++;
	}
	size = 0;
	while (size < size1)
	{
		total[i] = s2[size];
		i++;
		size++;
	}
	total[i] = '\0';
	return (total);
}

char	*fill_line(char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc((ft_strlen(s1) + 1) * sizeof(const char));
	if (s == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int	check(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		if(string[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
char	*get_line(char * nline)
{
	char	*line;
	int		i;
	
	i = 0;
	if(!nline[i])
		return (NULL);
	if (check(nline) == 0)
		line = fill_line(nline);
	else
	{
		line = malloc(ft_strchr(nline, '\n') - nline + 1);
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




char	*readfile(int fd, char *nlines)
{
	char	*aux;
	int		size;

	size = 1;
	aux = malloc(BUFFER_SIZE + 1); //+1
	if (aux == NULL)
	{
		free (nlines);
		return (NULL);
	}
	while (nlines && size > 0 && check(nlines) == 0)
	{
		size = read(fd, aux, BUFFER_SIZE);
		if (size == -1)
		{
			free (aux);
			free (nlines);
			return (NULL);
		}
		aux[size] = '\0';
		nlines = ft_strjoin(nlines, aux);
	}
	free (aux);
	return (nlines);
}
char	*next_line(char *nlines)
{
	char	*line;

	if(!nlines)
		return (NULL);
	if (check(nlines) == 0)
	{
		free (nlines);
		return (NULL);
	}
	line = ft_strchr(nlines, '\n');
	line = fill_line(line);
	free (nlines);
	return(line);
	

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

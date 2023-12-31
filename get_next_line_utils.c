/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <ajoya-pi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:56:44 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/12/27 13:37:42 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i] + 1);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
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

char	*ft_strjoin(char *s1, char *s2)
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
	{
		free (s1);
		return (NULL);
	}
	while (i < size)
	{
		total[i] = s1[i];
		i++;
	}
	size = 0;
	while (size < size1)
		total[i++] = s2[size++];
	total[i] = '\0';
	free (s1);
	return (total);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:13:51 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/12/09 12:13:09 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2571357
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

char    *get_next_line(int fd);

//UTILS FROM LIBFT
char	*ft_strdup(char *s1);
size_t  ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
#endif
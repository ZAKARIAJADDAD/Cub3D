/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-wad <zael-wad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:37:52 by zael-wad          #+#    #+#             */
/*   Updated: 2023/01/09 10:05:47 by zael-wad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t lenth);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *source);
size_t	ft_strchr(char *str, int c);
#endif
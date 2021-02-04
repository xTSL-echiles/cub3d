/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:04:07 by echiles           #+#    #+#             */
/*   Updated: 2020/12/01 13:04:10 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef	struct		s_costil
{
	char			*buf;
	int				ret;
}					t_costil;

int					get_next_line(int fd, char **cp_str, int j);
char				*ft_strrchr(const char *s, int c);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s1, char c);
char				*ft_strdup1(const char *s1, char c);
int					ft_strlen(const char *s, char c);
#endif

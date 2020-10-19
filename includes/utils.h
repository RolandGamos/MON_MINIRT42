/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:28:10 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/15 16:29:17 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "minirt.h"

# define BUFFER_SIZE 128

char		*ft_strdup(char *s);
int	        ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char *s, int start, int len);
int			ft_strlenc(char *str, char c);
char		*ft_strjoin(char *s1, char *s2);
void		ft_bzero(void *s, size_t n);
int		    get_next_line(int fd, char **line);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:27:56 by lweglarz          #+#    #+#             */
/*   Updated: 2020/10/19 17:09:57 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char		*ft_strdup(char *s)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (start > ft_strlenc(s, '\0'))
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

int			ft_strlenc(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}

char		*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;
	int				size;

	size = ft_strlenc(s1, '\0') + ft_strlenc(s2, '\0');
	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

void		ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

int		ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	isnegative;

	nbr = 0;
	isnegative = 1;
	i = 0;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			isnegative = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (isnegative * nbr);
}

float	ft_atof2(char *nptr)
{
	float	dec;
	float	ent;
	int		isnegative;
	int		size;

	isnegative = 1;
	while ((*nptr >= 8 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			isnegative = -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		ent = ent * 10 + (*nptr - '0');
		nptr++;
	}
	size = ft_strlen(nptr++) - 1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		dec = dec * 10 + (*nptr - '0');
		nptr++;
	}
	while (size--)
		dec /= 10;
	return ((dec + ent) * isnegative);
}
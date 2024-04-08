/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtoroyan <vtoroyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:54:56 by vtoroyan          #+#    #+#             */
/*   Updated: 2024/03/20 18:14:24 by vtoroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2, int f)
{
	char	*res;
	size_t	con1;
	size_t	con2;

	if (!s1 || !s2)
		return (NULL);
	con1 = 0;
	con2 = 0;
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s1[con1])
	{
		res[con1] = s1[con1];
		con1++;
	}
	while (s2[con2])
	{
		res[con1 + con2] = s2[con2];
		con2++;
	}
	res[con1 + con2] = '\0';
	if (f == 1)
		free (s1);
	return (res);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	res = malloc(sizeof(char) * (count + 1));
	if (res == NULL)
		return (NULL);
	count = 0;
	while (s[count] != '\0')
	{
		res[count] = s[count];
		count++;
	}
	res[count] = '\0';
	return (res);
}

char	*ft_substr(char *s, unsigned int start, size_t len, int f)
{
	size_t	count;
	char	*sub;
	size_t	mem;		

	if (!s || len == 0)
		return (NULL);
	count = 0;
	mem = ft_strlen(s + start);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len < mem)
		mem = len;
	sub = malloc((mem + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (count < mem)
	{
		sub[count] = s[count + start];
		count++;
	}
	sub[count] = '\0';
	if (f == 1)
		free (s);
	return (sub);
}

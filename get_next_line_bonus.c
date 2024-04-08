/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtoroyan <vtoroyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:54:26 by vtoroyan          #+#    #+#             */
/*   Updated: 2024/03/20 18:16:12 by vtoroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_strchr(const char *str, int c)
{
	int	count;

	count = 0;
	if (!str)
		return (-1);
	while (str[count] != '\0')
	{
		if (str[count] == c)
			return (count);
		count++;
	}
	if (str[count] == c)
		return (count);
	return (-1);
}

static char	*ft_get_result(char *buf)
{
	long long	count;
	char		*result;

	count = 0;
	if (!buf)
		return (NULL);
	count = ft_strchr(buf, '\n');
	if (count == -1)
		result = ft_substr(buf, 0, ft_strlen(buf), 0);
	else
		result = ft_substr(buf, 0, count + 1, 0);
	return (result);
}

static char	*ft_get_buf(char *buf)
{
	long long	count;
	char		*result;
	char		*temp;

	count = 0;
	temp = NULL;
	if (!buf)
		return (NULL);
	count = ft_strchr(buf, '\n');
	if (count == -1)
	{
		free (buf);
		return (NULL);
	}
	result = ft_substr(buf, count + 1, ft_strlen(buf) - count, 0);
	free (buf);
	return (result);
}

static char	*ft_read_line(int fd, char *buf)
{
	char		*temp;
	long long	size;

	size = 1;
	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (ft_strchr(buf, '\n') == -1 && size != 0)
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (size == -1)
		{
			free (buf);
			free (temp);
			return (NULL);
		}
		temp[size] = '\0';
		if (!buf)
			buf = ft_strdup("");
		buf = ft_strjoin(buf, temp, 1);
	}
	free (temp);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*result_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = ft_read_line(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	result_line = ft_get_result(buf[fd]);
	buf[fd] = ft_get_buf(buf[fd]);
	return (result_line);
}

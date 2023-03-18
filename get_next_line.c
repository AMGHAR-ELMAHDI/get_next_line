/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:18:11 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/17 15:39:44 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_var;
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_var = ft_read_until_new_line(fd, static_var);
	if (!static_var)
		return (NULL);
	return_line = ft_seperate_new_line(static_var);
	static_var = ft_get_remainder(static_var);
	return (return_line);
}

char	*ft_read_until_new_line(int fd, char *static_var)
{
	int		number_of_bytes_read;
	char	*buffer;

	number_of_bytes_read = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (number_of_bytes_read > 0 && !ft_strchr(static_var, '\n'))
	{
		number_of_bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (number_of_bytes_read == -1)
			return (free(buffer), free(static_var), NULL);
		buffer[number_of_bytes_read] = '\0';
		static_var = ft_strjoin(static_var, buffer);
	}
	return (free(buffer), static_var);
}

char	*ft_seperate_new_line(char *static_var)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!static_var[i])
		return (NULL);
	while (static_var[i] != '\n' && static_var[i])
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	while (static_var[j] && j <= i)
	{
		line[j] = static_var[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_get_remainder(char *static_var)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (static_var[i] != '\n' && static_var[i])
		i++;
	if (i == ft_strlen(static_var))
		return (free(static_var), NULL);
	str = malloc(ft_strlen(static_var) - i + 1);
	if (!str)
		return (NULL);
	i++;
	while (static_var[i])
		str[j++] = static_var[i++];
	str[j] = '\0';
	free(static_var);
	static_var = NULL;
	return (str);
}

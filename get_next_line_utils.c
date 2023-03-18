/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:19:57 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/17 15:33:53 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	char	*str2;
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(str);
	str2 = (char *)malloc((length + 1) * sizeof(char));
	if (!str2)
		return (NULL);
	while (i < length)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*ft_strjoin(char *static_var, char *buffer)
{
	char	*str;
	int		i;
	int		j;
	int		length;

	if (!static_var)
		static_var = ft_strdup("");
	if (!buffer)
		return (NULL);
	i = -1;
	j = 0;
	length = (ft_strlen(static_var) + ft_strlen(buffer));
	str = malloc(length + 1);
	if (!str)
		return (NULL);
	while (static_var[++i] != '\0')
		str[i] = static_var[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[length] = '\0';
	free(static_var);
	static_var = NULL;
	return (str);
}

int	ft_strlen(char *str)
{
	int	j;

	j = 0;
	if (!str)
		return (0);
	while (str[j] != '\0')
		j++;
	return (j);
}

int	ft_strchr(char *str, char find)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!find)
		return (ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] == find)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

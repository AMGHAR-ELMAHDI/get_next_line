/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:20:36 by eamghar           #+#    #+#             */
/*   Updated: 2023/03/17 15:34:44 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_read_until_new_line(int fd, char *static_var);
char	*ft_seperate_new_line(char *static_var);
char	*ft_get_remainder(char *static_var);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *static_var, char *buffer);
int		ft_strlen(char *str);
int		ft_strchr(char *str, char find);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <naddino@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:16:13 by naddino           #+#    #+#             */
/*   Updated: 2021/05/04 14:50:55 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

int		ft_get_next_line(int fd, char **line);
int		get_buffer(int fd, char *buf, size_t size);
size_t	ft_strnllen(char *str);
int		malloc_res(char **res, char *buf);
int		is_nl_into(char *str);
int		reset_buffer(char *buf);

#endif

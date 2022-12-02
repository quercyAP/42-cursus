/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:24:43 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/02 13:02:14 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_strlen(char *str);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_clean(char **rest);
int		ft_strlen(char *str);
char	*ft_strcat(char *str, char *src);
char	*ft_strdup(char *str);

#endif

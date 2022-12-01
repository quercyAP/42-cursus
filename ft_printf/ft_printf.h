/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:33:51 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/17 10:34:02 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(char c, int *nb);
int		ft_printstr(char *str, int *nb);
int		ft_printnbr(int n, int *nb);
size_t	ft_strlen(const char *str);
int		ft_printnbr_base(unsigned long int nbr, char *base, int *nb);
int		ft_printaddr(unsigned long int addr, int *nb);
int		ft_printunbr(unsigned int n, int *nb);

#endif

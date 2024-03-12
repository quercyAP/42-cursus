/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2022/11/25 13:34:05 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	ft_putstr_pf(char *s, int *count)
{
	unsigned int	i;

	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		(*count) += 6;
		return (0);
	}
	i = 0;
	while (s[i])
	{
		if (write(1, (s + i), 1) == -1)
			return (-1);
		i++;
		(*count)++;
	}
	return (0);
}

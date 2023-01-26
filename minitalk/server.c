/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:19:40 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/26 15:10:05 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	handler(int sig)
{
	static char	r_char;
	static int	count;

	if (sig == SIGUSR1)
		r_char = r_char | (0 << (7 - count));
	else
		r_char = r_char | (1 << (7 - count));
	count++;
	if (count == 8)
	{
		ft_printf("%c", r_char);
		count = 0;
		r_char = 0;
	}
}

int	main(void)
{
	ft_printf("PID : %i\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}
	return (0);
}

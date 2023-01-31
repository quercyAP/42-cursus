/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:45:44 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/31 18:08:48 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;

	if (argc > 1)
	{
		stack_a = check_error(argv, argc);
		if (stack_a == NULL)
			return (0);
		stack_b = ft_calloc(sizeof(int), stack_len(stack_a));
		free(stack_a);
		free(stack_b);
	}
}

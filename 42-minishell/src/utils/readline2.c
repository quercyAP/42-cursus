/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:08:25 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/08 13:54:26 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_debug(char **read_strs, char *msg)
{
	printf("%s", msg);
	print_tab(read_strs);
}

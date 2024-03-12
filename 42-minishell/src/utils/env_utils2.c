/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:56:29 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/14 16:23:45 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_free(char *str)
{
	free(str);
	str = NULL;
}

int	is_squote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

int	is_dquote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

int	char_check(char c)
{
	if (ft_isalnum(c) || c == '_' || c == '?')
		return (1);
	return (0);
}

int	browse_arg(char	*arg, int *i, char c, char **tmp)
{
	int	j;

	j = 0;
	while (arg[++(*i)] && (arg[*i] != c || arg[*i] != '\''))
		j++;
	*tmp = ft_substr(arg, ((*i) - j), j);
	return (j);
}

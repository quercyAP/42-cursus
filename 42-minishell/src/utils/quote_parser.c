/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:59:02 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/20 10:37:34 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*free_ret(char **strs)
{
	free(strs);
	strs = NULL;
	return (strs);
}

int	browse_arg2(char *arg, int *i, char c)
{
	int	j;

	j = 0;
	while (arg[++*i] && arg[*i] != c)
		j++;
	return (j);
}

char	*d_quotes_clean(char *str, t_data *data, t_list *clean_list)
{
	if (str[0] == '\'')
		add_string(&clean_list, ft_strdup(str), data);
	else
		add_string(&clean_list, clean_arg(str, data), data);
	return (list_to_arg(str, &clean_list));
}

static char	*qp_routine(char *str, t_data *data,
		char *clean_str, t_list *clean_list)
{
	char	**tmp;
	int		i;

	if (!str)
		return (NULL);
	tmp = quote_splitter(str);
	i = 0;
	if (tmp)
	{
		while (tmp[i])
		{
			if (tmp[i][0] == '\'' || tmp[i][0] == '\"')
				add_string(&clean_list, ft_substr(tmp[i], 1,
						ft_strlen(tmp[i]) - 2), data);
			else
				add_string(&clean_list, ft_strdup(tmp[i]), data);
			i++;
		}
		free_strs(tmp);
	}
	return (list_to_arg(clean_str, &clean_list));
}

char	**quote_parser(char **strs, t_data *data)
{
	int		i;
	int		j;
	char	**ret;

	if (!strs)
		return (NULL);
	ret = ft_calloc(sizeof(char *), ft_strtab_len(strs) + 1);
	i = -1;
	j = 0;
	while (strs[++i])
		ret[j++] = qp_routine(strs[i], data, NULL, NULL);
	if (!ret[0])
		ret = free_ret(ret);
	free_strs(strs);
	return (ret);
}

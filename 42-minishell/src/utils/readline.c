/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:08:25 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/20 10:39:08 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	unlen(char **strs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			k++;
			j++;
		}
		i++;
	}
	return (k);
}

char	*unsplit(char **strs)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	k = 0;
	i = 0;
	if (!strs)
		return (NULL);
	ret = ft_calloc(sizeof(char), (unlen(strs) + 1));
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
			ret[k++] = strs[i][j++];
		i++;
	}
	return (ret);
}

static char	**env_parser(char **strs, t_data *data)
{
	int		i;
	int		j;
	char	**tmp;

	if (!strs)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		tmp = quote_splitter(strs[i]);
		if (tmp)
		{
			j = -1;
			while (tmp[++j])
				tmp[j] = d_quotes_clean(tmp[j], data, NULL);
			free(strs[i]);
			strs[i] = unsplit(tmp);
			free_strs(tmp);
		}
		i++;
	}
	return (strs);
}

char	**ft_readline(t_data *data)
{
	char	*buff;
	char	**read_strs;

	buff = readline(PROMPT);
	if (!buff)
	{
		data->request_quit = 1;
		return (NULL);
	}
	add_history(buff);
	buff = string_cleaner(buff, *data);
	if (!buff)
		return (NULL);
	read_strs = ms_split(buff, data, 0);
	if (data->debug)
		print_debug(read_strs, "Sortie de split\n");
	read_strs = env_parser(read_strs, data);
	if (data->debug)
		print_debug(read_strs, "Sortie de env_parser\n");
	read_strs = quote_parser(read_strs, data);
	if (data->debug)
		print_debug(read_strs, "Sortie de quote_parser\n");
	free(buff);
	return (read_strs);
}

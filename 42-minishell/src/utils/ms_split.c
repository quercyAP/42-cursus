/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 13:24:59 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*copy_til(char **str, t_data *data)
{
	char	*str_begin;
	int		i_end;

	str_begin = *str;
	i_end = 0;
	while (**str && **str == ' ')
	{
		(*str)++;
		str_begin = *str;
	}
	while (**str)
	{
		check_d_quotes(str, data);
		check_s_quotes(str, data);
		if (**str == ' ' && data->quotes == CLOSED)
			return (ft_substr(str_begin, 0, (i_end)));
		i_end++;
		(*str)++;
	}
	if (i_end > 0)
		return (ft_substr(str_begin, 0, (i_end + 1)));
	return (NULL);
}

char	**init_tab(t_list *list)
{
	t_list	*local;
	int		i;
	char	**ret;

	i = 0;
	local = list;
	while (list)
	{
		i++;
		list = list->next;
	}
	ret = ft_calloc(sizeof(char *), i + 1);
	if (!ret)
		return (NULL);
	return (ret);
}

static char	**clrlst_return(t_list **list_begin, char **ret, t_data *data)
{
	ft_lstclear_nc(list_begin);
	if (!ret[0])
	{
		free(ret);
		return (NULL);
	}
	if (data->quotes == OPEN)
		data->error = QUOTES_OPENED_ERROR;
	return (ret);
}

char	**ms_split(char *s, t_data *data, int i)
{
	t_list	*list_begin;
	t_list	*list_cur;
	char	**ret;
	char	*tmp;

	if (!s || !(*s))
		return (NULL);
	list_begin = ft_lstnew((void *)copy_til(&s, data));
	if (!list_begin)
		return (NULL);
	while (*s)
	{
		tmp = copy_til(&s, data);
		if (tmp)
			ft_lstadd_back(&list_begin, ft_lstnew((void *)tmp));
	}
	ret = init_tab(list_begin);
	list_cur = list_begin;
	while (list_cur && ret)
	{
		ret[i] = (char *)list_cur->content;
		list_cur = list_cur->next;
		i++;
	}
	return (clrlst_return(&list_begin, ret, data));
}

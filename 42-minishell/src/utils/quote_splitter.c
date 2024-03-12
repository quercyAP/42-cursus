/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_splitter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:09:00 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/15 15:10:21 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*copy_til(char **str, char c)
{
	char	*str_begin;
	int		i_end;

	str_begin = *str;
	i_end = 0;
	(*str)++;
	while (**str)
	{
		if (**str == c)
		{
			(*str)++;
			return (ft_substr(str_begin, 0, (i_end + 2)));
		}
		i_end++;
		(*str)++;
	}
	if (i_end > 0)
		return (ft_substr(str_begin, 0, (i_end + 1)));
	return (NULL);
}

static char	*copy_til_next(char **str)
{
	char	*str_begin;
	int		i_end;

	str_begin = *str;
	i_end = 0;
	while (**str)
	{
		if (**str == '\'' || **str == '\"')
			return (ft_substr(str_begin, 0, (i_end)));
		i_end++;
		(*str)++;
	}
	if (i_end > 0)
		return (ft_substr(str_begin, 0, (i_end + 1)));
	return (NULL);
}

static char	**clrlst_return(t_list **list_begin, char **ret)
{
	ft_lstclear_nc(list_begin);
	if (!ret[0])
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

static void	addtolist(char **str, t_list **lst)
{
	char	*tmp;

	tmp = NULL;
	if (**str == '\'')
	{
		tmp = copy_til(str, '\'');
		if (tmp)
			ft_lstadd_back(lst, ft_lstnew(tmp));
	}
	else if (**str == '\"')
	{
		tmp = copy_til(str, '\"');
		if (tmp)
			ft_lstadd_back(lst, ft_lstnew(tmp));
	}
	else
	{
		tmp = copy_til_next(str);
		if (tmp)
			ft_lstadd_back(lst, ft_lstnew(tmp));
	}
}

char	**quote_splitter(char *str)
{
	char	**ret;
	t_list	*lst;
	int		i;
	t_list	*lst_cur;
	char	*tmp;

	i = 0;
	lst = NULL;
	while (*str)
	{
		addtolist(&str, &lst);
	}
	ret = init_tab2(lst);
	lst_cur = lst;
	while (lst_cur && ret)
	{
		ret[i] = (char *)lst_cur->content;
		lst_cur = lst_cur->next;
		i++;
	}
	return (clrlst_return(&lst, ret));
}

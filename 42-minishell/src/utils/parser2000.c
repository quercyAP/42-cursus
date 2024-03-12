/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2000.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:43:31 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 14:55:18 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**last_sep_heredoc(t_list **lexer_lst, t_data *data, int *run)
{
	t_list		*local;
	enum e_type	type;

	local = *lexer_lst;
	while (local->next)
	{
		local = local->next;
	}
	type = ((t_token *)(local->content))->type;
	if (type == PIPE || type == OR || type == AND
		|| type == AR_PLAN || type == SEMI_COLON)
		return (rl_sep_heredoc(data, run));
	return (NULL);
}

t_list	*parser2000(t_data *data)
{
	t_list	*ret;
	t_list	*lexer_lst;
	int		run;

	lexer_lst = NULL;
	ret = NULL;
	run = TRUE;
	while (data->prompt_tab)
	{
		lexer(&lexer_lst, data->prompt_tab);
		free_strs((*data).prompt_tab);
		data->prompt_tab = NULL;
		if (data->debug)
			print_lexer(lexer_lst);
		if (token_error(&lexer_lst, data))
			return (NULL);
		data->prompt_tab = last_sep_heredoc(&lexer_lst, data, &run);
	}
	if (!run)
		return (NULL);
	parsing(&ret, lexer_lst, data);
	ft_lstclear(&lexer_lst, &free_lex);
	args_tab_maker(ret);
	make_pipe(ret);
	return (ret);
}

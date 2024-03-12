/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:53:36 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 10:45:17 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_LIST_H
# define DISPLAY_LIST_H

void	display_list(t_list	*list);
void	print_tab(char **char_tab);
void	print_list(t_list	*list);
void	print_listenv(t_list	*list);
void	print_state(int state);
void	print_lexer(t_list *lexer_lst);
void	print_cmdtype(enum e_cmdtype cmdtype);
void	print_state(int state);
void	print_quote(enum e_quote quote);
void	plexer_utils(t_token *token);
void	print_pipe(t_cmd *cmd);
void	print_list_redir(t_list	*list);
void	print_link(enum e_type type);

#endif

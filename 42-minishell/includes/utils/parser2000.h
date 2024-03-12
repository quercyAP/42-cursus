/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2000.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:43:42 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/10 10:23:37 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER2000_H
# define PARSER2000_H

t_list		*parser2000(t_data *data);
int			make_node(t_list **cmd_lst, t_cmd **cmd, int *new_node,
				t_data *data);
int			lexer(t_list **lexer_lst, char	**str_tab);
void		make_pipe(t_list *list);
char		**args_list_maker(t_cmd *cmd);
enum e_type	get_type(char *str);
void		set_pipe(t_token *token, t_cmd *cmd, int *cmd_found, int *new_node);
void		set_or(t_token *token, t_cmd *cmd, int *cmd_found, int *new_node);
void		set_and(t_token *token, t_cmd *cmd, int *cmd_found, int *new_node);
void		set_arplan(t_token *token, t_cmd *cmd, int *cmd_found,
				int *new_node);
void		set_sc(t_token *token, t_cmd *cmd, int *cmd_found, int *new_node);
t_redir		*make_redir(enum e_type type, char *str);
void		set_cmd_param_sep(t_token *token, t_cmd *cmd,
				int *cmd_found, int *new_node);
void		set_redir_in_ps(t_token *token, t_cmd *cmd, t_list **lexer_lst);
void		set_redir_out_ps(t_token *token, t_cmd *cmd, t_list **lexer_lst);
int			parsing(t_list **cmd_lst, t_list *lexer_lst, t_data *data);
int			token_error(t_list **lexer_lst, t_data *data);
int			error_sep(t_list **lexer_lst, char *str, t_data *data);
int			error_redir(t_list **lexer_lst);
void		free_lex(void *arg);
int			args_tab_maker(t_list *cmd_lst);

#endif

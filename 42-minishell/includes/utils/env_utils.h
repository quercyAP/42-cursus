/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:33:14 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/23 09:50:15 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

char	*get_env(t_list *list_env, char *var);
t_list	*set_listenv(char **penv);
void	set_envnode(char *env, t_list **list_env);
t_env	*env_is_declare(t_list *env_list, char *name);
char	*clean_arg(char *arg, t_data *data);
void	ms_unset(t_cmd *cmd);
void	ms_env(t_cmd *cmd);
t_env	**sort_env(t_list *env_list);
void	*copy(void *content);
int		char_check(char c);
void	add_string(t_list **clean_list, char *str, t_data *data);
char	*list_to_arg(char *clean_str, t_list **clean_list);
int		browse_arg(char	*arg, int *i, char c, char **tmp);
char	*d_quotes_clean(char *str, t_data *data, t_list *clean_list);
char	*clean_quote(char *arg, t_data *data, char *clean_str,
			t_list *clean_list);
int		is_dquote(char *str);
int		is_squote(char *str);
void	clean_free(char *str);
int		browse_arg2(char *arg, int *i, char c);
char	**quote_parser(char **strs, t_data *data);
char	*unsplit(char **strs);
void	display_envutils(t_env *env);

#endif

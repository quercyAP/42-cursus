/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:50:37 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/15 15:33:53 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_CHECK_H
# define PARSER_CHECK_H

int		check_cmd_path(t_cmd **cmd);
char	*cmd_parser(char *cmd);
int		check_dot_slash(t_cmd **cmd);

#endif

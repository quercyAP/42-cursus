/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:42:30 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/08 13:38:32 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_CLEANER_H

void	manag_redir(t_cmd *cmd, t_launch *tool);
int		check_redir_out(t_cmd *cmd, t_launch *tool);
void	manag_out(t_cmd *cmd, t_launch *tool);

#endif

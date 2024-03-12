/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:35:03 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 15:03:34 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_CD_H
# define MS_CD_H

void	ms_cd(t_cmd *cmd);
char	*cd_back(char *str);
char	*getabspath(char *current_path, char *r_or_abs_path);
void	cd_error(char *cur_dir, char *goto_dir, t_cmd *cmd);
void	set_env(char *cur_dir, char *goto_dir, t_cmd *cmd);
char	*cd_moins(char *old_pwd, t_cmd *cmd);

#endif

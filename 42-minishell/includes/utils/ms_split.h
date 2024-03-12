/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:04:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 13:24:48 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SPLIT_H
# define MS_SPLIT_H

char	**ms_split(char *s, t_data *data, int i);
void	check_d_quotes(char **str, t_data *data);
void	check_s_quotes(char **str, t_data *data);

#endif

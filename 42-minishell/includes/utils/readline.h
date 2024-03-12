/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:48:46 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 13:53:48 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

/*
@brief Gestion de l'affichage du prompt et de l'historique
@return renvoi un tableau de string de toute les commandes
*/
char	**ft_readline(t_data *data);
void	print_debug(char **read_strs, char *msg);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:51:08 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/01 10:05:47 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_H
# define HANDLE_H

/*
@brief Gestion du sginal Ctrl + C
*/
void	handle_sigquit(int sig);
/*
@brief Gestion du sginal Ctrl + \
*/
void	handle_sigint(int sig);
void	signal_manager(t_data *data);

#endif

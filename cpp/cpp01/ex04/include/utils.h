/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:29:28 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/10 11:36:08 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <string>
# include <fstream>
# include <sstream>
# include <iostream>

bool copy_file(const std::string &src_filename, const std::string &dest_filename);
bool replace_in_file(const std::string &filename, const std::string &s1, const std::string &s2);

#endif
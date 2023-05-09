/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:27:55 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/09 19:29:53 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

bool copy_file(const std::string &src_filename, const std::string &dest_filename)
{
    std::ifstream src(src_filename.c_str());
    std::ofstream dest(dest_filename.c_str());
    
    if (!src.is_open() || !dest.is_open())
        return false;

    dest << src.rdbuf();
    return true;
}

bool replace_in_file(const std::string &filename, const std::string &s1, const std::string &s2) 
{
    std::string output_filename = filename + ".replace";

    if (!copy_file(filename, output_filename)) 
        return false;

    std::fstream output_file(output_filename.c_str());
    if (!output_file.is_open()) 
        return false;

    std::stringstream buffer;
    buffer << output_file.rdbuf();
    std::string file_contents = buffer.str();

    size_t pos = 0;
    while ((pos = file_contents.find(s1, pos)) != std::string::npos) 
	{
        file_contents.erase(pos, s1.length());
        file_contents.insert(pos, s2);
        pos += s2.length();
    }

    output_file.seekp(0);
    output_file << file_contents;
    output_file.close();
    return true;
}

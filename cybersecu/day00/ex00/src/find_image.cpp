/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_image.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:43:43 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/15 14:31:41 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/spider.h"

std::vector<std::string> find_image(std::string html)
{
	std::vector<std::string> links;
	std::regex img_regex("<img[^>]*src=\"([^\"]*)\"[^>]*>");

	auto img_begin = std::sregex_iterator(html.begin(), html.end(), img_regex);
	auto img_end = std::sregex_iterator();

	for (std::sregex_iterator i = img_begin; i != img_end; ++i)
	{
		std::smatch match = *i;
		std::string match_str = match[1].str();
		links.push_back(match_str);
	}
	return links;
}
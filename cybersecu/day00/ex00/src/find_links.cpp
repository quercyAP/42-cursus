/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_links.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:43:53 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/15 13:46:19 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/spider.h"

std::vector<std::string> find_links(std::string html)
{
	std::vector<std::string> links;
	std::regex link_regex("<a[^>]*href=\"([^\"]*)\"[^>]*>");

	auto link_begin = std::sregex_iterator(html.begin(), html.end(), link_regex);
	auto link_end = std::sregex_iterator();

	for (std::sregex_iterator i = link_begin; i != link_end; ++i)
	{
		std::smatch match = *i;
		std::string match_str = match[1].str();
		// std::cout << match_str << std::endl;
		links.push_back(match_str);
	}
	return links;
}
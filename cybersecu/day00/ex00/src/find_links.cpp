/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_links.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:43:53 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/17 09:33:13 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/spider.h"

static std::string extractDomain(const std::string& url)
{
    size_t start = 0;
    if (url.find("http://") == 0) {
        start = 7;
    } else if (url.find("https://") == 0) {
        start = 8;
    }
    size_t end = url.find("/", start);
    if (end == std::string::npos) {
        end = url.length();
    }
    return url.substr(0, end);
}

static std::string cleanURL(const std::string& url, const std::string& domain)
{
    std::string cleaned_url = url;
    size_t pos = url.find("/url?q=");
    if (pos != std::string::npos) {
        cleaned_url = url.substr(pos + 7);
    }
    if (cleaned_url[0] == '/') {
        cleaned_url = domain + cleaned_url;
    }
    if (cleaned_url.find("https://wordpress") != std::string::npos)
    {
        size_t pos = cleaned_url.find("https://wordpress");
        cleaned_url.replace(pos, 18, "https://www");
    }  
    if (cleaned_url.find(domain) == std::string::npos)
        return "";
    return cleaned_url;
}

std::vector<std::string> find_links(std::string html, std::string domain)
{
	std::vector<std::string> links;
	std::regex link_regex("<a[^>]*href=\"([^\"]*)\"[^>]*>");

	auto link_begin = std::sregex_iterator(html.begin(), html.end(), link_regex);
	auto link_end = std::sregex_iterator();

	for (std::sregex_iterator i = link_begin; i != link_end; ++i)
	{
		std::smatch match = *i;
		std::string match_str = match[1].str();
        std::string tmp = cleanURL(match_str, extractDomain(domain));
        if (tmp == "")
            continue ;
		links.push_back(cleanURL(match_str, extractDomain(domain)));
	}
	return links;
}
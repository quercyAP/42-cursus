/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_image.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:43:43 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/16 10:36:07 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/spider.h"

static std::string cleanURL(const std::string& url)
{
    std::string cleaned_url = url;
    if (cleaned_url.find("https://wordpress") != std::string::npos)
    {
        size_t pos = cleaned_url.find("https://wordpress");
        cleaned_url.replace(pos, 18, "https://www.");
    }
    return cleaned_url;
}

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
        
        std::filesystem::path p(match_str);
        std::string extension = p.extension().string();

        // Convertir en minuscule pour faciliter la comparaison
        // std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

        if (extension == ".jpg" || extension == ".jpeg" || extension == ".png" || extension == ".gif" || extension == ".bmp")
        {
            std::string tmp = cleanURL(match_str);
            if (tmp == "")
                continue;
            links.push_back(tmp);
        }
    }
    return links;
}
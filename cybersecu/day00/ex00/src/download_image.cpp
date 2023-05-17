/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download_image.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:49:36 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/17 14:00:55 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/spider.h"

#include <string>

static std::string find_name(std::string url)
{
    std::size_t found = url.find_last_of("/");

    if (found != std::string::npos) {
        std::string filename = url.substr(found+1);

        return filename;
    }
    else
        return "";
}

static bool check_doublon(std::string name, std::string path)
{
    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        if (entry.path().filename() == name)
            return true;
    }

    return false;
}


void download_image(std::vector<std::string> img_links, std::string path) 
{
    CURL* curl;
    FILE* fp;

    curl = curl_easy_init();
    if (curl)
    {
        std::filesystem::path dir(path);
        if (!std::filesystem::exists(dir))
            std::filesystem::create_directories(dir);
        for (std::string url : img_links)
        {
            std::string filename = find_name(url);
            if (check_doublon(filename, path))
                continue;
               
            std::cout << url << std::endl;
            
            std::string fullpath = path + "/" + filename;
            fp = fopen(fullpath.c_str(),"wb");
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK)
            {
                std::cerr << "Erreur lors de la requête : " << curl_easy_strerror(res) << std::endl;
                std::cerr << "URL : " << url << std::endl;
            }
            fclose(fp);
        }
        curl_easy_cleanup(curl);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download_image.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:49:36 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/16 09:36:32 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/spider.h"

void download_image(std::vector<std::string> img_links, std::string path) 
{
    CURL* curl;
    FILE* fp;
    static int counter;

    curl = curl_easy_init();
    if (curl)
    {
        std::filesystem::path dir(path);
        if (!std::filesystem::exists(dir))
            std::filesystem::create_directories(dir);
        for (std::string url : img_links)
        {
            std::filesystem::path p(url);
            std::string extension = p.extension().string();

            std::cout << url << std::endl;
            
            std::string filename = "output" + std::to_string(counter) + extension;
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
            ++counter;
        }
        curl_easy_cleanup(curl);
    }
}
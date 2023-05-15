/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download_image.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:49:36 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/15 14:53:39 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/spider.h"

void download_image(std::vector<std::string> img_links, std::string path) 
{
    CURL* curl;
    FILE* fp;
    CURLcode res;
    static int counter;

    curl = curl_easy_init();
    if (curl)
	{
        std::__fs::filesystem::path dir(path);
        if (!std::__fs::filesystem::exists(dir))
            std::__fs::filesystem::create_directories(dir);
        for (std::string url : img_links)
        {
            std::string filename = "output" + std::to_string(counter) + ".jpg";
            std::string fullpath = path + "/" + filename;
            fp = fopen(fullpath.c_str(),"wb");
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            res = curl_easy_perform(curl);
            fclose(fp);
            ++counter;
        }
        curl_easy_cleanup(curl);
    }
}
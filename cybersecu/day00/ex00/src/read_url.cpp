/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_url.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:08:52 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/15 20:52:16 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/spider.h"

std::string read_url(const char *url, std::string path)
{
	curl_global_init(CURL_GLOBAL_ALL);

	CURL* curl = curl_easy_init();
	if (curl) 
	{
		std::string buffer;

		// Définir l'URL à récupérer
		curl_easy_setopt(curl, CURLOPT_URL, url);

		// Définir la fonction de rappel
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

		// Effectuer la requête
		CURLcode res = curl_easy_perform(curl);
		if (res != CURLE_OK)
		{
			std::cerr << "Erreur lors de la requête : " << curl_easy_strerror(res) << std::endl;
			std::cerr << "URL : " << url << std::endl;
			return "";
		}
		// download_image(find_image(buffer), path);
		curl_easy_cleanup(curl);
		return buffer;
	}
	return "";
}
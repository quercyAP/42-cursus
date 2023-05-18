/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_url.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:08:52 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/17 14:17:27 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/spider.h"

std::string read_url(const char *url)
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
			std::ifstream file(url);
			if (file) {
				std::stringstream tmp;
				tmp << file.rdbuf();
				// std::cout << tmp.str() << std::endl;
				return tmp.str();
			} else {
				std::cerr << "Erreur lors de l'ouverture du fichier : " << url << std::endl;
				return "";
			}
			std::cerr << "Erreur lors de la requête : " << curl_easy_strerror(res) << std::endl;
			std::cerr << "URL : " << url << std::endl;
			return "";
		}
		curl_easy_cleanup(curl);
		return buffer;
	}
	return "";
}
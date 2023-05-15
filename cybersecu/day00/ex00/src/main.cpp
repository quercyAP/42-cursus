/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:15:08 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/15 15:51:18 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/spider.h"

void read_url(char *url, std::string path)
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
		if (res == CURLE_OK)
			download_image(find_image(buffer), path);
		else
			std::cerr << "Erreur lors de la requête : " << curl_easy_strerror(res) << std::endl;

		curl_easy_cleanup(curl);
	}

}

int main(int argc, char** argv) 
{
    int option;
    bool r_flag = false;
    bool l_flag = false;
	int max_depth = 5;
	std::string path = "data";

    // Utilisation de getopt pour analyser les options
    while ((option = getopt(argc, argv, "rl:p:")) != -1) 
	{
        switch (option) {
            case 'r':
                r_flag = true;
                break;
			case 'l':
				l_flag = true;
				if (optarg != nullptr) {
					try {
						int depth = std::stoi(optarg);
						if (depth > 0) {
							max_depth = depth;
						} else {
							std::cerr << "-l doit être supérieur à 0." << std::endl;
							return 1;
						}
					} catch (const std::invalid_argument& ia) {
						std::cerr << "Option -l nécessite un entier valide." << std::endl;
						return 1;
					} catch (const std::out_of_range& oor) {
						std::cerr << "Option -l dépasse la plage des entiers valides." << std::endl;
						return 1;
					}
				}
				break;
			case 'p':
				if (optarg != nullptr) {
					if (optind == argc && optarg == argv[optind - 1]) {
						std::cerr << "Option -p nécessite un argument." << std::endl;
						return 1;
					}
					path = optarg;
				}
				break;
            default:
                std::cerr << "Utilisation : ./spider [-rlp] URL" << std::endl;
                return 1;
        }
    }

    // Récupération de l'URL (argument non-optionnel)
    if (optind < argc) 
        read_url(argv[optind], path);
	else 
	{
        std::cerr << "URL manquante." << std::endl;
        return 1;
    }

    // Faites quelque chose en fonction des options activées
    if (r_flag)
        std::cout << "Option r activée." << std::endl;
    if (l_flag)
        std::cout << "Option l activée." << std::endl;	

	curl_global_cleanup();
    return 0;
}

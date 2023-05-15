/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:15:08 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/15 22:23:03 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/spider.h"	

int main(int argc, char** argv) 
{
    int option;
    bool r_flag = false;
	int max_depth = 5;
	std::string path = "data";

    while ((option = getopt(argc, argv, "rl:p:")) != -1) 
	{
        switch (option) {
            case 'r':
                r_flag = true;
                break;
			case 'l':
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

	std::string html;
    if (optind < argc) 
        html = read_url(argv[optind], path);
	else 
	{
        std::cerr << "URL manquante." << std::endl;
        return 1;
    }

    if (r_flag)
	{
		std::unordered_set<std::string> visited;
		recursive(html, argv[optind], visited, 0, max_depth, path); 	
        std::cout << "Option r activée." << std::endl;
	}
	else
	{
		std::unordered_set<std::string> visited;
		recursive(html, argv[optind], visited, 0, 1, path); 	
        std::cout << "Option r désactivée." << std::endl;
	}

	curl_global_cleanup();
    return 0;
}

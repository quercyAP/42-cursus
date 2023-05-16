/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recusrcive.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:22:00 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/16 10:25:51 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/spider.h"

void non_recursive(std::string html, std::string domain,
std::unordered_set<std::string>& visited, std::string path)
{

    std::vector<std::string> links(find_links(html, domain));

    for (std::string link : links)
    {
        // Vérifie si le lien a déjà été visité
        if (visited.find(link) == visited.end())
        {
            // Si le lien n'a pas été visité, il est ajouté à l'ensemble des liens visités
            visited.insert(link);

            // Faites vos opérations sur le lien ici
            // std::cout << link << std::endl;

            // Faire une nouvelle requête à cette URL et récursivement trouver les liens sur cette page
            std::string newHtml = read_url(link.c_str(), ""); 
            
            // Trouver les liens des images et les télécharger
            std::vector<std::string> img_links = find_image(newHtml);
            download_image(img_links, path);
        }
    }
}

void recursive(std::string html, std::string domain,
std::unordered_set<std::string>& visited, int current_depth, int max_depth,
std::string path)
{
    if (current_depth > max_depth)
        return;

    std::vector<std::string> links(find_links(html, domain));

    int next_depth = current_depth +1;
    
    for (std::string link : links)
    {
        // Vérifie si le lien a déjà été visité
        if (visited.find(link) == visited.end())
        {
            // Si le lien n'a pas été visité, il est ajouté à l'ensemble des liens visités
            visited.insert(link);

            // Faites vos opérations sur le lien ici
            // std::cout << link << std::endl;

            // Faire une nouvelle requête à cette URL et récursivement trouver les liens sur cette page
            std::string newHtml = read_url(link.c_str(), ""); 
            
            // Trouver les liens des images et les télécharger
            std::vector<std::string> img_links = find_image(newHtml);
            download_image(img_links, path);

            recursive(newHtml, domain, visited, next_depth, max_depth, path);
        }
    }
}

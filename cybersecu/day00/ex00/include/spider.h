/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:44:56 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/15 14:51:17 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPIDER_H
#define SPIDER_H

#include <vector>
#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <unistd.h>
#include <filesystem>

std::vector<std::string> find_links(std::string html);
std::vector<std::string> find_image(std::string html);
void download_image(std::vector<std::string> img_links, std::string path);

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer);
size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream);

#endif
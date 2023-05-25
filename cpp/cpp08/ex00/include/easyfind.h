/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigui <guigui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:23:14 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/25 15:22:35 by guigui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

template<typename T>
void easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Number not found in container.");
    else
        std::cout << "Found: " << *it << std::endl;
}
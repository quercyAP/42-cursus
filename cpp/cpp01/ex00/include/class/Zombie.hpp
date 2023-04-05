/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:01:28 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/05 14:43:05 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.h"

class Zombie
{
	private:
		std::string name;
		
	public:
		Zombie();
		~Zombie();
		void anounce(void);
		void setName(std::string name);
		std::string getName();
};
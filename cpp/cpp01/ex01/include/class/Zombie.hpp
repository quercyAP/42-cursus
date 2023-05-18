/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:45:55 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/09 14:46:04 by glamazer         ###   ########.fr       */
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
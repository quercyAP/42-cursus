/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:30:34 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 20:44:31 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>
# include "Animal.hpp"

class Brain
{
	private:
		std::string ideas[100];
		int currentIdea;
	
	public:
		Brain( void );
		Brain ( Brain const &src );
		~Brain ( void );
		
		Brain &operator=( Brain const &copy);
		void addIdea( std::string idea );
		void printIdeas( void ) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:50:56 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 21:09:10 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>
# include "Brain.hpp"


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"


class Brain;

class Animal
{
	protected:
		std::string type;
	
	public:
		Animal( void );
		Animal( Animal const &src );
		virtual ~Animal( void );
		
		virtual Animal &operator=( Animal const &copy );

		virtual void makeSound( void ) const;
		
		std::string getType( void ) const;
		virtual Brain *getBrain( void ) const;
		virtual void setBrain( Brain *brain );

};

#endif
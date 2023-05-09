/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:50:56 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/09 15:54:01 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string type;
	
	public:
		Animal( void );
		Animal( Animal const &src );
		~Animal( void );
		
		Animal &operator=( Animal const &copy );

		virtual void makeSound( void ) const;
		
		std::string getType( void ) const;
};

#endif
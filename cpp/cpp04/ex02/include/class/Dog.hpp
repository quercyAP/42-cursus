/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:43:02 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 20:22:56 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	
	public:
		Dog( void );
		Dog( Dog const &src );
		~Dog( void );
		
		Dog &operator=( Dog const &copy );
		
		void makeSound( void ) const;

		Brain *getBrain() const;
		void setBrain( Brain *brain );
};

#endif
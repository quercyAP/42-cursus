/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:21:22 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 20:21:46 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;

	public:
		Cat( void );
		Cat( Cat const &src );
		~Cat( void );
		
		Cat &operator=( Cat const &copy );
		
		void makeSound( void ) const;
		Brain *getBrain( void ) const;
		void setBrain( Brain *brain );

};

#endif
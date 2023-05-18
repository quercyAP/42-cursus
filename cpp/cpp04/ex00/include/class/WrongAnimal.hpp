/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:18:31 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/10 09:19:11 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	
	public:
		WrongAnimal( void );
		WrongAnimal( WrongAnimal const &src );
		virtual ~WrongAnimal( void );
		
		WrongAnimal &operator=( WrongAnimal const &copy );

		void makeSound( void ) const;
		
		std::string getType( void ) const;
};

#endif
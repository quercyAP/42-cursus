/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:06:11 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 22:14:28 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

#define MAX_INVENTORY_SIZE 4

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[MAX_INVENTORY_SIZE];
	
	public:
		Character(std::string const &name);
		virtual ~Character();
		
		std::string const &getName( void ) const;
		
		void equip( AMateria *m );
		void unequip( int idx );
		void use( int idx, ICharacter &target );
};

#endif
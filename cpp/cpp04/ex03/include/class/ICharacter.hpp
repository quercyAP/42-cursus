/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:59:05 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 22:16:06 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICharacter
# define ICharacter

# include "AMateria.hpp"

class ICharacter
{
	public:
		virtual ~ICharacter( void );
		virtual std::string const &getName( void ) const = 0;
		virtual void equip( AMateria *m ) = 0;
		virtual void unequip( int idx ) = 0;
		virtual void use( int idx, ICharacter &target ) const = 0;
};

#endif
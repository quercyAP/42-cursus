/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:39:25 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 22:01:42 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;

	public:
		AMateria( std::string const &type );
		virtual ~AMateria( void );

		std::string const &getType( void ) const;
		virtual AMateria *clone( void ) const = 0;
		virtual void use( ICharacter &target ) const = 0;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:35:52 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/12 09:19:26 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource( void );
		virtual void learnMateria( AMateria *m ) = 0;
		virtual AMateria *createMateria( std::string const &type ) = 0;
};

#endif
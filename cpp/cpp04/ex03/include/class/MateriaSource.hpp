/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:19:28 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 22:34:06 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METARIASOURCE_HPP
# define METARIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
#define MAX_INVENTORY_SIZE 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *learnedMateria[MAX_INVENTORY_SIZE];
	
	public:
		MateriaSource( void );
		virtual ~MateriaSource( void );

		void learnMateria( AMateria *m );
		AMateria *createMateria( std::string const &type );
};

#endif
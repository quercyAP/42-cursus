/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:04:08 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/10 12:33:40 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>


class Harl
{
	public:
		Harl( void );
		~Harl( void );
		
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void complain( std::string level);
};

typedef void (Harl::*funcptr)( void );

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:03:45 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/10 12:42:39 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/Harl.hpp"

int	main( void )
{
	Harl toto;

	toto.complain("debug");
	toto.complain("info");
	toto.complain("warning");
	toto.complain("error");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:13:09 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/05 12:45:50 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#endif

class Fixed
{
	private:
		int	value;
		static const int bits;
	
	public:
		Fixed();
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed(const Fixed &copy);
		~Fixed();
		
		Fixed &operator=(const Fixed &copy);
		
		int getRawBits(void) const;
		void setRawBits(const int raw);
		float toFloat(void) const;
		int toInt(void) const;
};

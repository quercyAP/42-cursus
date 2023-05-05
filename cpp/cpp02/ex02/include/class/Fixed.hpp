/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:13:09 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/05 15:29:59 by glamazer         ###   ########.fr       */
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
		Fixed operator+(const Fixed &copy) const;
		Fixed operator-(const Fixed &copy) const;
		Fixed operator/(const Fixed &copy) const;
		Fixed operator*(const Fixed &copy) const;
				
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		
		// bool operator>(const Fixed &copy);
		// bool operator<(const Fixed &copy);
		// bool operator>=(const Fixed &copy);
		// bool operator<=(const Fixed &copy);
		// bool operator==(const Fixed &copy);
		// bool operator!=(const Fixed &copy);
		
		int getRawBits(void) const;
		void setRawBits(const int raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &nb);
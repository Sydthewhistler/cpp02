#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>


class Fixed
{

	public :

	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed();
	Fixed& operator=(const Fixed &nb2);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;


	private :

	int m_nb;
	static const int m_bitnb = 8;


};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed_nb);

#endif
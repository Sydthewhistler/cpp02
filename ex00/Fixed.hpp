#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>


class Fixed
{

	public :

	Fixed();
	Fixed(const Fixed &other);
	~Fixed();
	Fixed& operator=(const Fixed &nb2);
	int getRawBits( void ) const;
	void setRawBits( int const raw );


	private :

	int m_nb;
	static const int m_bitnb = 8;


};


#endif
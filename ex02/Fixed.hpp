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
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	Fixed& operator=(const Fixed &nb2);
	bool operator>(const Fixed  &other) const;
	bool operator>=(const Fixed  &other) const;
	bool operator<(const Fixed  &other) const;
	bool operator<=(const Fixed  &other) const;
	bool operator==(const Fixed  &other) const;
	bool operator!=(const Fixed  &other) const;
	float operator+(const Fixed &other) const;
	float operator-(const Fixed &other) const;
	float operator*(const Fixed &other) const;
	float operator/(const Fixed &other) const;
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed& min(Fixed &nb1, Fixed &nb2);
	static const Fixed& min(const Fixed &nb1, const Fixed &nb2);
	static Fixed& max(Fixed &nb1, Fixed &nb2);
	static const Fixed& max(const Fixed &nb1, const Fixed &nb2);


	private :

	int m_nb;
	static const int m_bitnb = 8;


};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed_nb);

#endif
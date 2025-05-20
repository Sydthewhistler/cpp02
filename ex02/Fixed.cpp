#include "Fixed.hpp"


Fixed::Fixed() : m_nb(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->operator=(other);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &nb2)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if(this != &nb2)
	{
		this->m_nb = nb2.m_nb;
	}
	return *this;
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;

	return (m_nb);
}

void Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	m_nb = raw;
}

Fixed::Fixed(const int nb)
{
	//std::cout << "Int constructor called" << std::endl;
	m_nb = nb << m_bitnb;
}

Fixed::Fixed(const float nb)
{
	//std::cout << "Float constructor called" << std::endl;
	m_nb = static_cast<int>(roundf(nb * (1 << m_bitnb)));
}

float Fixed::toFloat( void ) const
{
	return (static_cast <float>(m_nb) / (1 << m_bitnb));
}

int Fixed::toInt( void ) const
{
	return (m_nb >> m_bitnb);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed_nb)
{
	out << fixed_nb.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed  &other) const
{
	return (this->toFloat() > other.toFloat());
}
bool Fixed::operator>=(const Fixed  &other) const
{
	if(*this > other || *this == other)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed  &other) const
{
	return (this->toFloat() < other.toFloat());
}
bool Fixed::operator<=(const Fixed  &other) const
{
	if(*this == other || *this < other)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed  &other) const
{
	return (this->toFloat() == other.toFloat());
}
bool Fixed::operator!=(const Fixed  &other) const
{
	return not (*this == other);
}

float	Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

float	Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	m_nb++;
	return (*this);
}
Fixed& Fixed::operator--()
{
	m_nb--;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	m_nb++;
	return (temp);
}
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	m_nb--;
	return (temp);
}

Fixed& Fixed::min(Fixed &nb1, Fixed &nb2)
{
	return(nb1 > nb2 ? nb2 : nb1);
}

const Fixed& Fixed::min(const Fixed &nb1, const Fixed &nb2)
{
	return(nb1 > nb2 ? nb2 : nb1);
}
Fixed& Fixed::max(Fixed &nb1, Fixed &nb2)
{
	return(nb1 < nb2 ? nb2 : nb1);
}
const Fixed& Fixed::max(const Fixed &nb1, const Fixed &nb2)
{
	return(nb1 < nb2 ? nb2 : nb1);
}
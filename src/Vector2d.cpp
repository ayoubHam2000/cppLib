#include "Vector2d.hpp"

Vector2d::Vector2d(): _x(0.0), _y(0.0)
{

}

Vector2d::Vector2d(double a): _x(a), _y(a)
{

}

Vector2d::Vector2d(double a, double b): _x(a), _y(b)
{

}

Vector2d::Vector2d(const Vector2d &obj)
{
	*this = obj;
}

Vector2d::~Vector2d()
{

}

double	Vector2d::getX() const
{
	return (_x);
}

double	Vector2d::getY() const
{
	return (_y);
}

Vector2d	&Vector2d::operator=(const Vector2d &obj)
{
	if (this != &obj)
	{
		this->_x = obj._x;
		this->_y = obj._y;
	}
	return (*this);
}

Vector2d	Vector2d::operator+(const Vector2d &obj)
{
	Vector2d	res;

	res._x = this->_x + obj._x;
	res._y = this->_y + obj._y;
	return (res);
}

Vector2d	Vector2d::operator-(const Vector2d &obj)
{
	Vector2d	res;

	res._x = this->_x - obj._x;
	res._y = this->_y - obj._y;
	return (res);
}

Vector2d	Vector2d::operator*(const Vector2d &obj)
{
	Vector2d	res;

	res._x = this->_x * obj._x;
	res._y = this->_y * obj._y;
	return (res);
}

bool	Vector2d::operator==(const Vector2d &obj)
{
	return (this->_x == obj._x && this->_y == obj._y);
}

bool	Vector2d::operator!=(const Vector2d &obj)
{
	return (this->_x != obj._x || this->_y != obj._y);
}

void	Vector2d::normalize()
{
	double	len = length();
	_x /= len;
	_y /= len;
}

double	Vector2d::length()
{
	return (sqrt(_x * _x + _y * _y));
}

void	Vector2d::rotate(double angle)
{
	_x = _x * cos(angle) + _y * sin(angle);
	_y = _y * cos(angle) - _x * sin(angle);
}

std::ostream	&operator<<(std::ostream &out, const Vector2d &obj)
{
	out << "(" << obj.getX() << ", " << obj.getY() << ")";
	return (out);
}

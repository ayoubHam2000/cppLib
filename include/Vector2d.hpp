#ifndef VECTOR_2D_HPP
#define VECTOR_2D_HPP

#include <iostream>
#include <cmath>

class	Vector2d
{
private:
	double	_x;
	double	_y;
public:
	Vector2d();
	Vector2d(double a);
	Vector2d(double a, double b);
	Vector2d(const Vector2d &obj);
	~Vector2d();
	Vector2d	&operator=(const Vector2d &obj);
	Vector2d	operator+(const Vector2d &obj);
	Vector2d	operator-(const Vector2d &obj);
	Vector2d	operator*(const Vector2d &obj);
	double		getX() const;
	double		getY() const;
	bool	operator==(const Vector2d &obj);
	bool	operator!=(const Vector2d &obj);
	void	normalize();
	double	length();
	void	rotate(double angle);
};

std::ostream	&operator<<(std::ostream &out, const Vector2d &obj);

#endif

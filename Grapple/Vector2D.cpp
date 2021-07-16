#include "Vector2D.h"

Vector2D::Vector2D()
{
	Vector2D(0, 0);
}


Vector2D Vector2D::operator+(Vector2D& v2)
{
	return Vector2D(x + v2.x, y + v2.y);
}

Vector2D Vector2D::operator-(Vector2D& v2)
{
	return Vector2D(x - v2.x, y - v2.y);
}

Vector2D Vector2D::operator*(float f)
{
	return Vector2D(x*f, y*f);
}

Vector2D Vector2D::operator/(float f)
{
	return Vector2D(x/f, y/f);
}

void Vector2D::ones()
{
	this->x = 1;
	this->y = 1;
}

void Vector2D::zeroes()
{
	this->x = 0;
	this->y = 0;
}
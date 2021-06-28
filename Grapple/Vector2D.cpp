#include "Vector2D.h"

Vector2D::Vector2D()
{
	Vector2D(0, 0);
}

Vector2D::Vector2D(float x, float y)
{
	this->xpos = x;
	this->ypos = y;
}

Vector2D Vector2D::operator+(Vector2D& v2)
{
	return Vector2D(xpos + v2.x(), ypos + v2.y());
}

Vector2D Vector2D::operator-(Vector2D& v2)
{
	return Vector2D(xpos - v2.x(), ypos - v2.y());
}

Vector2D Vector2D::operator*(float f)
{
	return Vector2D(xpos*f, ypos*f);
}

Vector2D Vector2D::operator/(float f)
{
	return Vector2D(xpos/f, ypos/f);
}

void Vector2D::ones()
{
	this->xpos = 1;
	this->ypos = 1;
}

void Vector2D::zeroes()
{
	this->xpos = 0;
	this->ypos = 0;
}

float& Vector2D::x()
{
	return xpos;
}

float& Vector2D::y()
{
	return ypos;
}

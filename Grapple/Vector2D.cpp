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

void Vector2D::operator+=(Vector2D& v2) {
	x += v2.x;
	y += v2.y;
}

void Vector2D::operator-=(Vector2D& v2) {
	x -= v2.x;
	y -= v2.y;
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

float Vector2D::magnitude() {
	if (this->x == INFINITY || this->y == INFINITY) {
		return INFINITY;
	}
	return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

Vector2D Vector2D::perpendicular() {
	Vector2D v;
	v.x = -this->y / this->magnitude();
	v.y = this->x / this->magnitude();
	return v;
}
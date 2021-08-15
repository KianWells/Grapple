#pragma once
#include <iostream>

class Vector2D {
public:
    Vector2D();
    Vector2D(float xPos, float yPos) : x(xPos), y(yPos) {}
    virtual ~Vector2D() {};

    Vector2D operator+(Vector2D& v2);
    Vector2D operator-(Vector2D& v2);
    Vector2D operator*(float f);
    Vector2D operator/(float f);
    void operator+=(Vector2D& v2);
    void operator-=(Vector2D& v2);
    void ones();
    void zeroes();
    float magnitude();
    Vector2D perpendicular();

    friend std::ostream& operator<<(std::ostream& os, Vector2D& v) {
        os << "(" << v.x << "," << v.y << ")";
        return os;
    }

    float x, y;
};
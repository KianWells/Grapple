#pragma once
#include <iostream>

class Vector2D {
public:
    Vector2D();
    Vector2D(float x, float y);
    virtual ~Vector2D() {};

    Vector2D operator+(Vector2D& v2);
    Vector2D operator-(Vector2D& v2);
    Vector2D operator*(float f);
    Vector2D operator/(float f);
    void ones();
    void zeroes();

    float& x();
    float& y();

    friend std::ostream& operator<<(std::ostream& os, Vector2D& v) {
        os << "(" << v.x() << "," << v.y() << ")";
        return os;
    }
private:
    float xpos, ypos;
};
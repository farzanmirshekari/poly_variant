#include "poly_variant.h"

#include <iostream>

class Shape
{
public:
    virtual ~Shape() = default;
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    void draw() override
    {
        std::cout << "Circle" << std::endl;
    }
};

class Square : public Shape
{
public:
    void draw() override
    {
        std::cout << "Square" << std::endl;
    }
};

class Triangle : public Shape
{
public:
    void draw() override
    {
        std::cout << "Triangle" << std::endl;
    }
};

class NotShape
{
public:
    void draw()
    {
        std::cout << "Not a shape" << std::endl;
    }
};

int main()
{
    poly_variant<Shape, Circle, Square, Triangle> shape;
    shape = Circle();
    shape->draw();
    shape = Square();
    shape->draw();
    shape = Triangle();
    shape->draw();

    /**
    * cannot do this:
    * poly_variant<Shape, Circle, Square, Triangle, NotShape> shape;
    * or this:
    * shape = NotShape();
    */
}
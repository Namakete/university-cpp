// Copyright (c) Namakete (Ilya Oberemok) <namakete.dev@gmail.com>.
// See the LICENCE file in the repository root for full licence text.

#include <algorithm>
#include <functional>
#include <iostream>
#include <list>

#define PI 3.14

class Functor {
   public:
    double operator()(double &value) const;
};
/*
 * @brief - Multiplies each element of a list of floating point numbers by a PI number.
 */
double Functor::operator()(double &value) const {
    value = value * PI;
    return value;
}
/*
 * @brief - Contains information about the position of the shape's
 * center __x__ and __y__ coordinates.
 */
class Shape {
   protected:
    int _x;
    int _y;

   public:
    explicit Shape();

    explicit Shape(int _x, int _y);

    bool isMoreLeft(const Shape *pShape) const;
    bool isUpper(const Shape *pShape) const;
    virtual void draw() const = 0;
};

/*
 * @brief - Empty constructor.
 */
Shape::Shape() : _x(0), _y(0) {}
/*
 * @brief - Constructor for redefining figure coordinate values.
 */
Shape::Shape(int _x, int _y) : _x(_x), _y(_y) {}
/*
 * @brief - Allowing to determine whether the given figure is located to the left
 * (determined by the position of the center) than the figure passed as an argument
 */
bool Shape::isMoreLeft(const Shape *pShape) const {
    return (_x < pShape->_x);
}
/*
 * @brief - Allows you to determine whether the given figure is located higher
 * (determined by the position of the center) than the figure passed as an argument.
 */
bool Shape::isUpper(const Shape *pShape) const {
    return (_y > pShape->_y);
}

class Circle : public Shape {
   public:
    explicit Circle();

    explicit Circle(int _x, int _y);

    virtual void draw() const override;
};

Circle::Circle() : Shape() {}

Circle::Circle(int _x, int _y) : Shape(_x, _y) {}

void Circle::draw() const {
    std::cout << "Circle: " << _x << ", " << _y << std::endl;
}

class Triangle : public Shape {
   public:
    explicit Triangle();

    explicit Triangle(int _x, int _y);

    virtual void draw() const override;
};

Triangle::Triangle() : Shape() {}

Triangle::Triangle(int _x, int _y) : Shape(_x, _y) {}

void Triangle::draw() const {
    std::cout << "Triangle: " << _x << ", " << _y << std::endl;
}

class Square : public Shape {
   public:
    explicit Square();

    explicit Square(int _x, int _y);

    virtual void draw() const override;
};

Square::Square() : Shape() {}

Square::Square(int _x, int _y) : Shape(_x, _y) {}

void Square::draw() const {
    std::cout << "Square: " << _x << ", " << _y << std::endl;
}

int main() {
    std::list<double> values = {2.4, 3.0, 5.1, 0.4, 2.0, 1.5};

    std::for_each(values.begin(), values.end(), Functor());

    for (double &value : values) {
        std::cout << value << std::endl;
    }

    Circle circle(4, 2);
    Triangle triangle(3, 7);
    Square square(5, 6);
    Square squar(4, 6);

    std::list<Shape *> figure;

    figure.push_back(&circle);
    figure.push_back(&triangle);
    figure.push_back(&square);
    figure.push_back(&squar);

    std::cout << "\nleft->right: " << std::endl;
    figure.sort(std::mem_fn(&Shape::isMoreLeft));
    std::for_each(figure.begin(), figure.end(), std::mem_fn(&Shape::draw));

    std::cout << "\nright->left: " << std::endl;
    figure.sort(std::mem_fn(&Shape::isMoreLeft));
    std::reverse(std::begin(figure), std::end(figure));
    std::for_each(figure.begin(), figure.end(), std::mem_fn(&Shape::draw));

    std::cout << "\nUP: " << std::endl;
    figure.sort(std::mem_fn(&::Shape::isUpper));
    std::for_each(figure.begin(), figure.end(), std::mem_fn(&::Shape::draw));

    std::cout << "\nDOWN: " << std::endl;
    figure.sort(std::mem_fn(&::Shape::isUpper));
    std::reverse(std::begin(figure), std::end(figure));
    std::for_each(figure.begin(), figure.end(), std::mem_fn(&::Shape::draw));

    return 0;
}

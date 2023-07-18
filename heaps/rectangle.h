#pragma once

class Rectangle
{
public:
    Rectangle(double width = 1, double height = 1);
    Rectangle(const Rectangle &src); // add copy constructor which is deep copy
    ~Rectangle();
    double area();
    double perimeter();
    double getHeight();
    double getWidth();

private:
    double *height; // pointer to a double
    double *width; 
};
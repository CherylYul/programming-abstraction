#include "rectangle.h"

/*
 * Implementation notes
 * ---------------------------------------
 * The private variables are 2 int* pointers, we use new to allocate space
 * for the data for those pointers, so we don't have variables with names for
 * the data, but the data is still in memory
 * Ex: Rectangle r(3, 4);
 * r.width: 0x99 | 0x61 point to: 3 | 0x99
 * r.height: 0x9f | 0x63 point to 4 | 0x9f
 */
Rectangle::Rectangle(double width, double height) {
    this->width = new double; 
    this->height = new double;
    *(this->width) = width;
    *(this->height) = height;
}

Rectangle::~Rectangle() {
    delete height;
    delete width;
}

double Rectangle::area() {
    return *width * *height;
}

double Rectangle::perimeter() {
    return 2 * *width + 2 * *height;
}

double Rectangle::getHeight() {
    return *height;
}

double Rectangle::getWidth() {
    return *width;
}

//     Rectangle r(3,4);
//     cout << "Width: " << r.getWidth() << ", ";
//     cout << "Height: " << r.getHeight() << endl;
      
//     cout << "Area: " << r.area() << endl;
//     cout << "Perimeter: " << r.perimeter() << endl;
      
//     // let's make a copy:
//     Rectangle r2 = r; // THIS CRASHES!!!

/*
 * Why crashes? 
 * r2.width: 0x99 | 0x65
 * r2.height: 0x9f | 0x67
 * Now r.width and r2.width point to the same pointee, and likewise for r.height and r2.height. 
 * This is bad news! When the destructor gets called, both will try to delete the value that
 * was allocated, and this isn't allowed! The program crashes! What do we do? We define a copy
 * constructor that tells the compiler how to copy our class. Without it, it will simply copy
 * the values in the class variables, which isn't what we want in this case.
 */

Rectangle::Rectangle(const Rectangle &src) { // copy constructor
    width = new double; // request new memory
    height = new double;
      
    // copy the values
    *width = *src.width;
    *height = *src.height;
}
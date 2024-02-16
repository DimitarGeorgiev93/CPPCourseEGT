



#include "Circle.h"
#include "Rectangle.h"


//printArea method, takes a Shape pointer and polymorphicly calls that object's area method
void printArea(Shape* shape);


int main()
{

    Circle b(4);
    Rectangle c(5,2.3);

    std::cout << "Calling the printArea method with a circle object: ";
    printArea(&b);
    std::cout << "Calling the printArea method with a Rectangle object: ";
    printArea(&c);

    return 0;
}

//definition of the printArea function
void printArea(Shape* shape) {
    if (shape != nullptr) {
        std::cout << shape->area() << std::endl;
    }
}
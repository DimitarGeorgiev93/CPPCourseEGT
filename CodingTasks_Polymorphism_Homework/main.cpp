



#include "Circle.h"
#include "Rectangle.h"


//printArea method, takes a Shape pointer and polymorphicly calls that object's area method
void printArea(Shape* shape);


int main()
{

    Circle b( "red",4);
    Rectangle c("green",5,2.3);

    //std::cout << "Calling the printArea method with a circle object: ";
    printArea(&b);
    //std::cout << "Calling the printArea method with a Rectangle object: ";
    printArea(&c);

    return 0;
}

//definition of the printArea function
void printArea(Shape* shape) {
    if (shape != nullptr) {
        shape->draw();
        std::cout << shape->area() << std::endl;
    }
}
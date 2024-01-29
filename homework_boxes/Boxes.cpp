

#include "Box.h"

int main()
{
    Box a(2,2,4);
    Box b(2,2,10);
    std::cout << "Starting values: \na: ";
    a.printInfo();
    std::cout << "b: ";
    b.printInfo();
    
    std::cout << "Merging on z axis: \n";
    a = a + b;
    std::cout << "a: ";
    a.printInfo();
    std::cout << "setting b to (10,2,14)\n";
    b.setDimensions(10, 2, 14);
    a = a + b;
    std::cout << "Merging on x axis: \n";
    std::cout << "a: ";
    a.printInfo();

    std::cout << "setting b to (12,10,14)\n";
    b.setDimensions(12, 10, 14);
    a = a + b;
    std::cout << "Merging on y axis: \n";
    std::cout << "a: ";
    a.printInfo();
    std::cout << "setting b to (5,5,5) - cant be merged with a\n";
    b.setDimensions(5,5,5);
    a = a + b;
    std::cout << " a = a + b\n ";
    std::cout << "a: ";
    a.printInfo();
    std::cout << " did not merge, nothing happened \n ";
    a = b + a;
    std::cout << " a = b + a\n ";
    std::cout << "a: ";
    a.printInfo();
    std::cout << " did not merge, a copied b ( regular a = b)\n ";
}


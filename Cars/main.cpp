
#include <iostream>

#include"PremiumCar.h"

//enum Brand { Opel, BMW, Mazda, Shkoda, Kia, Audi, VW, Dacia };
//enum Colour { RED, BLACK, WHITE, GREY, GREEN, YELLOW, ORANGE, BLUE };
//enum Type { COMBI, HATCHBACK, SEDAN };

int main()
{
    Car a(Brand::Kia, "X-ceed", Type::HATCHBACK, Colour::BLUE, "12365478", "HJ1234KO", 7,50);
    PremiumCar b(PremTax::WINE, Brand::Kia, "X-ceed", Type::HATCHBACK, Colour::BLUE, "12365478", "HJ1234KO", 7, 50);
    a.print();
    b.print();

}
//Brand brand, std::string model, Type type, Colour colour, std::string id, std::string regPlate, double gas, double tax
//PremTax premimumTax, Brand brand, std::string model, Type type, Colour colour, std::string id, std::string regPlate, double gas, double tax
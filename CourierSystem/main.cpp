#include <iostream>

#include<vector>
#include "ExpressPackage.h"

int main()
{
    Adress a("Pencho Zlatev", "Sofiq", "Carigradsko shose", "123445");
    Adress b("Zlatko Penchev", "Varna", "Mosta za skachane", "987456");

    Package pack(a, b, 23, 2);
    ExpressPackage pack2(a, b, 23, 2, 10);

    std::vector<Package*> packages;
    packages.push_back(&pack);
    packages.push_back(&pack2);

    packages.push_back(&pack2);
    packages.push_back(&pack);
    packages.push_back(&pack2);
    packages.push_back(&pack);

    for (Package* package : packages) {
        std::cout << "----------------------" << std::endl;
        package->print();
    }
}


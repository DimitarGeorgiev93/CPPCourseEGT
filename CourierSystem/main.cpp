
#include <iostream>


#include "ExpressPackage.h"

int main()
{
    Adress a("Pencho Zlatev", "Sofiq", "Carigradsko shose", "123445");
    Adress b("Zlatko Penchev", "Varna", "Mosta za skachane", "987456");

    Package pack(a,b,23,2);
    ExpressPackage pack2(a,b,23,2,10);
    pack.print();
    pack2.print();
}


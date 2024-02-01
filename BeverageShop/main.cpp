#include <iostream>
#include "Shop.h"

int main()
{

    Alcohol a("Beer", "Kamenica", 2.54, 1, 3.2);
    NonAlcoholic b("Ice tea", "Nestea", 2.54, 1);
    Alcohol a1("Beer", "Zagorka", 1.76, 0.5, 4);
    NonAlcoholic b1("Fuzzy drink", "Coca-Cola", 2.7, 1.5);
    NonAlcoholic b2("Fuzzy drink", "Fanta", 2.7, 1.5);
    /*a.printInfo();
    a.setPrice(42);
    a.setName("potato");
    a.printInfo();
    b.printInfo();*/

    Shop shop("Takos & boritos");
    shop.addBeverage(&a, 1000);
    shop.addBeverage(&b, 1000);
    shop.addBeverage(&a1, 1000);
    shop.addBeverage(&b2, 1000);
    shop.addBeverage(&b1, 1000);
    Order o(&a,15);
    ///o.addToOrder(&a, 43);
    //o.addToOrder(&b, 43);
    Order o1(&a, 12);
    Order o2(&b1, 23);
    Order o3(&b2, 123);
    Order o4(&a1, 223);

    Customer c("Pesho Talev");
    Customer d("Ivo Kamenov");
    Customer e("Misho Shamara");
    c.addOrder(o);
    c.addOrder(o1);
    d.addOrder(o2);
    e.addOrder(o3);
    e.addOrder(o4);
    shop.addCustomer(&c);
    shop.addCustomer(&d);
    shop.addCustomer(&e);
    //c.printClientInfo();
    //shop.printSoldBeverages();
    //shop.printClientList();
    std::cout << "----------------------------------\n";
    shop.getCustomersByDrink(a);
    //std::cout << shop.getBestCustomer()->getName() << std::endl;
}
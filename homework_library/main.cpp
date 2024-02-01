

#include <iostream>


#include "Library.h"

int main()
{
   

    Author a("George", "R.R Martin", "Murica");
    Author a1("Ivan", "Vazov", "Bulgarian");
    Book b(&a, "A Game of Thrones", Fantasy, 2000);
    Book b1(&a, "A Clash of Kings", Fantasy, 2002);
    Book b2(&a, "A Storm of Swords", Fantasy, 2004);
    Book b3(&a, "A Feast for Crows", Fantasy, 2000);
    Book b4(&a, "A Dance with Dragons", Fantasy, 2000);
    Book b5(&a1, "Pod Igoto", Historical, 1894);
    Book b6(&a, "Gusla", Historical,1881 );
    Book b7(&a, "Izbavlenie", Historical, 1900);

    std::map<Book, int> bookList;
    bookList.insert({ b,1 });
    bookList.insert({ b1,1 });
    bookList.insert({ b2,1 });
    bookList.insert({ b3,1 });
    bookList.insert({ b4,1 });

    Library l2(bookList);
    Library l;
   // a.print();
    std::cout << std::endl;
   // b.print();
    l.addBook(b);
    l.addBook(b1);
    l.addBook(b2);
    l.addBook(b3);
    l.addBook(b4);
    l.addBook(b5);
    l.addBook(b6);
    l.addBook(b7);
    l.addBook(b4);

    std::cout << std::endl;
    //l.print();

    //l.lookByName("A Clash of Kings");
    l.lookByWord("Gusla");
    //l2.print();
}

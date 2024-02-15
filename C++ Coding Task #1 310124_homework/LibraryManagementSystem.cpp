
#include <iostream>
#include"Member.h"
#include <vector>


void initBookList(std::vector<Book>& );
void initMemberList(std::vector<Member>&);


int main()
{
    std::vector<Member> memberList;
    std::vector<Book> bookList;

    //initiliazing books and members
    initBookList(bookList);
    initMemberList(memberList);

   /* Member a("aasd", 23, "sdsdfsdfsdf");
    Book b("aas2234d", "aa23 42sd", "aas234234d");
    a.display();
    a.borrowBook(b);
    a.display();
    a.returnBook();
    a.display();*/

    // invoking display() in each member
    for (Member& member : memberList) {
        member.display();
    }

    // each member borrows a book
    for (int i = 0; i < memberList.size(); i++) {
        memberList.at(i).borrowBook(bookList.at(i));
    }

    // invoking display() again to show the borrowed book
    for (Member member : memberList) {
        member.display();
    }

    //returning books
    for (Member& member : memberList) {
        member.returnBook();
    }

    //final display invocation 
    for (Member member : memberList) {
        member.display();
    }

    return 0;
}

void initBookList(std::vector<Book>& bookList) {
    bookList.push_back(Book("A Game of Thrones", "G.R.R Martin", "978-3-16-168410-0"));
    bookList.push_back(Book("A Clash of Kings", "G.R.R Martin", "248-3-87-158621-2"));
    bookList.push_back(Book("A Feast for Crows", "G.R.R Martin", "928-3-11-178920-1"));
    bookList.push_back(Book("A Storm of Swords", "G.R.R Martin", "911-3-96-012568-5"));
    bookList.push_back(Book("A Dance with Dragons", "G.R.R Martin", "248-2-14-168410-9"));
};

void initMemberList(std::vector<Member>& memberList) {
    memberList.push_back(Member("Ivan Palev", 42, "975832"));
    memberList.push_back(Member("Cvetina Ilcheva", 30, "154863"));
    memberList.push_back(Member("Katq Nikolova", 21, "268232"));
    memberList.push_back(Member("Anton Karailiev", 15 , "856239"));
    memberList.push_back(Member("Desislav Ivanov", 56, "463586"));
}

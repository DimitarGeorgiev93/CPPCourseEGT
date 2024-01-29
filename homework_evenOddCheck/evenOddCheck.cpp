
#include <iostream>

void evenOrOdd(int n);

int main()
{
    
    int n;
    std::cout << "Enter a number, 0 will end the loop..\n";
    std::cin >> n;

    do {
        
        evenOrOdd(n);
        std::cout << "Enter a number, 0 will end the loop..\n";
        std::cin >> n;
    } while (n != 0);

    return 0;
}

void evenOrOdd(int n) {
     if(n%2==1) {
        std::cout << "odd\n";
    } 
    else std::cout << "even\n";
}
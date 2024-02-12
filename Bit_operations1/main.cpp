// 12022024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <queue>
#include<math.h>

int toBinary(int a) {
    std::stack<int> A;
    int b = 0;
    while (a > 0) {
        A.push(a % 2);
        a /= 2;
    }
    while (!A.empty()) {

        b *= 10;
        b += A.top();
        A.pop();
    }
    return b;
}

int toDecimal(int a) {
    int b = 0;
    std::queue<int> A;
    while (a > 0) {
        A.push(a%10);
        a /= 10;
    }
    int c = 0;
    while (!A.empty()) {
        b += A.front() * pow(2, c++);
        A.pop();
    }
    return b;
}

int main()
{
    std::cout << toBinary(234) << std::endl;
    std::cout << toDecimal(11101010) << std::endl;
}


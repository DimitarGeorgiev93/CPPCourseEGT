// ConsoleApplication9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<queue>

void calculateArr(std::queue<int>*que, int n) {
    
    int count = 1;
    int printCount = 0;
    que->push(n);
    while (count < 100) {
        que->push(que->front() + 1);
        que->push(2 * que->front() + 1);
        que->push(que->front() + 2);
        count += 3;
        std::cout << que->front() << std::endl;
        que->pop();
        printCount++;
    }
    while (printCount++<100) {

        std::cout << que->front() << std::endl;
        que->pop();
    }

}



int main()
{
    std::queue<int> que;
    int n; 
    std::cin >> n;
    calculateArr(&que, n);


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

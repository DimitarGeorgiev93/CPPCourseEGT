// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool isSubArray(const int* array1, const size_t size1, const int* array2, const size_t size2) {

    size_t i = 0; // smaller array
    size_t j = 0; // bigger array
    bool isSubArray = false;

    while (i < size1 && j < size2) {

        //cout << "Position i " << i << " array1: " << array1[i] << " Position j " << j << " array2: " << array2[j] << " Result: ";
        if (array1[i + j] != array2[j]) {
            i++;
            isSubArray = false;
        }
        else if (array1[i + j] == array2[j]) {
            j++;
            //i++;
            isSubArray = true;
        }
        //cout << isSubArray << endl;
    }

    return isSubArray;
}

int main()
{
    int a[] = { 2,2,2,2,2,3 };
    int b[] = { 2,2,3 };

    cout << isSubArray(a, 6, b, 3);

    return 0;
}


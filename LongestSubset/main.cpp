

#include<list>
#include<iterator>
#include <iostream>
#include<map>
#include <set>
#include<algorithm>

int ptrCounter(std::list<int>::iterator start, std::list<int>::iterator end) {
    int count = 0;
    while (start != end) {
        //std::cout << *start << std::endl;
        count++;
        start++;
    }
    return count;
}
void getLongestSub(std::list<int>* arr) {

    //arr->sort();

    std::list<int>::iterator nextEl = arr->begin();
    std::list<int>::iterator ptr = nextEl++;
    std::list<int>::iterator currentStart = arr->begin();
   // std::list<int>::iterator currentEnd = arr->begin();
    std::list<int>::iterator longestStart = arr->begin();
    std::list<int>::iterator longestEnd = arr->begin();



    while ( nextEl != arr->end()) {
        if (*ptr == *nextEl) {
            //std::cout << *ptr << std::endl;
            ptr++;
            nextEl++;
        }
        else {
            ptr++;
            if (ptrCounter(longestStart, longestEnd)< ptrCounter(currentStart,ptr)) {
                longestStart = currentStart;
                longestEnd = ptr;
            }
            if(nextEl!=arr->end()) nextEl++;
            currentStart = ptr;
            
        }
        std::cout << "longestStart: " << *longestStart << " ";
        std::cout << "longestEnd: " << *longestEnd << " ";
        std::cout << "length " << ptrCounter(longestStart, longestEnd) << " ";
        std::cout << "currentStart: " << *currentStart << " ";
        std::cout << "ptr: " << *ptr << " ";

       // std::cout << "nextEl: " << *nextEl;
        std::cout << std::endl;


    }

    while (longestStart != longestEnd) {
        std::cout << *longestStart++ << " ";
    }
}


int main()
{


    std::list<int> arr;


    int input = INT_MIN;
    int sum = 0;
    std::cin >> input;
    while (input != 0) {
        sum += input;
        arr.push_back(input);
        std::cin >> input;
    }
    std::cout << sum <<" " << sum / arr.size() << std::endl;

    getLongestSub(&arr);
    /*while (!arr.empty())
    {
        std::cout << arr.front() << " ";
        arr.pop_front();
    }*/
}


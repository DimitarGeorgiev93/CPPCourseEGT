#include <iostream>

using namespace std;
// Base Class declaration
class Base {
public:
    virtual void print()
    {
        cout << "Base" << endl;
    }
};

// Derived1 class declaration
class Derived1 : public Base {
public:
    void print()
    {
        cout << "Derived1" << endl;
    }
};

// Derived2 class declaration
class Derived2 : public Base {
public:
    void print()
    {
        cout << "Derived2" << endl;
    }
};

// Driver Code
int main()
{
    Derived1 d1;

    // Base class pointer holding
    // Derived1 Class object
   Base* bp = dynamic_cast<Base*>(&d1);
    //Base* bp = &d1;
    bp->Base::print();
    // Dynamic_casting
    Derived1* dp2 = dynamic_cast<Derived1*>(bp);
   //  Derived2* dp3 = dynamic_cast<Derived1*>(d1); - not possible
    if (dp1 == nullptr)
        cout << "null" << endl;
    else
        cout << "not null" << endl;

    dp2->Base::print();
    return 0;
}

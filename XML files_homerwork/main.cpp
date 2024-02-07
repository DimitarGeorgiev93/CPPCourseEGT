

#include "utility.h"

int main()
{
    std::vector<Employee*>* employees = doItAll("employees.xml");
    printAndDel(employees);
    deleteDynamicStuff(employees);
    
    
    return 0;
}


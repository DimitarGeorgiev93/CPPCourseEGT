

#include "Department.h"

void initEmployeeList(Department&);

int main()
{


    Department MoM("Ministry of Magic");

    //initilialize employeese
    initEmployeeList(MoM);

    //calling display()
    MoM.displayEmployees();


    return 0;
}

//helper function to initilialize employees
void initEmployeeList(Department& department) {
    department.addEmplyee(new Employee("Kingsley Shacklebolt", "158964","Auror"));
    department.addEmplyee(new Employee("Alastor Moody", "389524", "Auror"));
    department.addEmplyee(new Employee("Artur Weasly", "986261", "Head of Muggle-finds"));
    department.addEmplyee(new Employee("Pius Thicknesse", "859624", "Minister of magic"));
    department.addEmplyee(new Employee("Dolores Umbridge", "859625", "High-Inquisitor"));
}
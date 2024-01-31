#pragma once

1.Describe what the following line of C++ code does : int* ptr = @var;

//english
Creates a int* ( int pointer ) variable and sets it to point at the adress of an int variable var.
I assume it exists, if it doesnt it will not complile 
//български
Създава променлива от тип int* ( int pointer ) и и задава начална стойност адресът на променливата от тип int var. 
Ако тя не е инициализирана преди това, няма да се компилира.

2.Explain the differecne between a while and a do-while loop in C++:

//english
A while loop checks its requirement before any iterations are done, aka it can be entirely skipped if the requirement
is not met at the very start.A do - while loop checks the requirement after the each iteration, so it does 1 loop by default.
//български
while първо проверява дали е изпълнено условието и съответно може да не изпълни тялото си дори и веднъж ако то не е изпълнено
do - while прави проверка след изпълнение, така че с него ще направим една итерация със сигурност

3. for (int i = 0; i < 25; i++) {
	std::cout << i << " ";
};

//english
it prints the numbers from 0 to 24 in the console prompt, ending after that because i becomes 25 which fails the requirement(i < 25)
it iterates 25 fimes and stops after that
//български
изкарва числата от 0 до 24 на конзолата, цкълът приключва след това защото i става 25, което не отговаря на условието(i < 25)
цикълът ще се завърти 25 пъти

4.Write about how functions prevent code diplications and give an example of a simple C++ function that calculates teh square of a number.
//english
Functions prevent code duplications by replacing the blocks of the same code in the program with a call to said function.
//български
Функциите се използват когато имаме повтарящ се код, който можем да изнесем извън тялото на програмата, и да го заместим с call към съответната фунцкия.

int square(int a) {
	return a * a;
}


5.Discuss the importance of memory management in c++ and explain the difference between stack and heap memory allocation

//english
Memory management is required so that there is no waste of memory usage and that memory is allocated efficiantly.
The stack memory is faster to access than the heap, but it is less flexible.It allocates memory when a method / function
is called and frees it up after it has run its course.
The heap is slower, reuquires the programmer to free it up after use(delete), but it does allow us to create variables / objects
during runtime.

6.Explain the concept of encapsulation in c++ and how it is achieved using classes

//english
Encapsulation is taking the data/characteristics of something ( the member-variables) and the logic/functions/how it works ( the member-fucntions)
into one unit ( class/struct ) essentially hiding parts of them, leaving only the necessary ones to be visible to the outside.
Example: you dont really need to know how to a car worksunder the hood the drive one.

//български
Енкапсулацията в ООП е обеденението на характеристиките и функциите/логиката в един обект, като по този начин скрива части от обекта от външния 
свят, оставяйки само най-необходимото видимо ( Public functions ). Пример: не ти трябва да знаеш как работи двигателя на една кола за да я караш.

7.Describe how exceptions are used in C++ for error handling with an exmaple of a try-catch block
	
//english
Exceptions are errors the program might throw at us during runtime.We put the part of the code in a try {} block, and if an expection is thrown we 
catch it in the catch{} block after it, so that the program can keep running.

//български
Ексептионите са ерори които нашата програма може да хвърли по време на работа.Поставяме кода който може да хвърли такава грешка в try {} блок,
и ако такава грешка бива хвърлена, я прихващаме в catch{} блока след него.

try {
	int j = 10
	int i = 0;
	if (i == 0) {
		throw ( ...) // случай с делене на нула
	}
	
	std::cout << j / i;

} 
catch(..) {
	cerr << <error info> endl;
}

8.Write about the purpose and use of a std::vector container in C++

//english
Part of the STL, it creates a resizable array, it can be of any of data type, both basic(int, char ..) and custom(classes), has build in functions for
everything(push_back, erase, size).It is used whenever you need a collection of the same type of data to be stored.

//български
Част от STL библиотеката, представлява масив с променлива големина(променя се в зависимост колко елемента има в момента в него).Може да съдържа
както и основните типове данни, така и от обекти на даден клас.Използва се когато трябва да сторнираш данни от един и същ тип в линейна структура.

9.Disccuss the difference between pointers and references in c++ and provide scenarios where one might be preferred over the other
//english
A pointer can be initialized without a starting value(int* ptr;), but a reference has to have one(int& ref = a).
A call to the refence varible retrieves the data stored in the original right away, while with a pointer we have to use* ptr to do it, since it
stores the adress of that original variable;
You can change wher a pointer is pointing at, but you cannot do so on a reference.
Usage: references are mostly used in function parameters, and pointers - for pointer arritmentics, creating data structures ( linked list) and dynamic memory

//български
Указателя може само да се инициализара без стойност или с nullptr, докато референция трябва да сочи към дадена променлива от началото.
Когато викнем референцията, директно достъпваме стойността на оригиналната променлива ( референцията е просто нейно друго име), докато при
указателя трябва да го дерефиренцираме с *.
можем да променяме къде сочи указателя, докато при референциите това е невъзможно.
Използване: референциите се ползват главно при функции като тип на подаваната стойност, а указателите се използват също и при указателна аритметика
и при структурите от данни ( Linked list )

10.Explain the concept of templates in c++ and how they support generic programmic. Include a simple exmaple of a template function 
//english
Templates are used when you need to write a function that can work with multiple different data types ( they have to be the same type of type, but 
you are not limited to only 1 template parameter per function ) as a way to save on code.

//български
Template-ите се използват когато функции трябва да предоставят една и съща функционалност с различни типове данни ( те трябва да са от един тип, но
можем да подаваме повече от 1 различни templates на фунцкия) - спестяват кодене.

template<class T, class R> void foo(T a, R b) {
		...
}
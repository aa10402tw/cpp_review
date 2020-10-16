
```
#include<iostream>
using namespace std;
main() {	
   union abc {
		int x;
		char ch;
	} var;
	
   var.ch = 'A';
   cout<<var.x;
}
```
**What is the output of the following program?** <br/>
Ans: 65, as the union variables share common memory for all its elements, x gets ‘A’ whose ASCII value is 65 and is printed.

**Choose the respective delete operator usage for the expression ‘ptr=new int[100]’.** <br/>
Ans: delete[] ptr;

**Runtime polymorphism is done using.** <br/>
Ans: Virtual functions gives the ability to override the functionality of base class into the derived class. Hence achieving dynamic/runtime polymorphism.

**Which of the following approach is adapted by C++?** <br/>
Ans: Object oriented language such as C++/java/python uses **bottom up approach** where each object is identified first.

**Which of the following is not the member of class?** <br/>
Ans: Friend function

**Which of the following is correct about the statements given below?** <br/>
**All operators can be overloaded in C++.** <br/>
**We can change the basic meaning of an operator in C++.**
Ans: Both I and II are false

**Which one of the following is the correct way to declare a pure virtual function** <br/>
Ans: virtual void Display(void) = 0;

**Which of the following statements regarding inline functions is correct?** <br/>
Ans: It speeds up execution. It increases the code size.

**In which of the following a virtual call is resolved at the time of compilation?** <br/>
Ans: From inside the destructor. From inside the constructor.

**Which of the following operators cannot be overloaded?** <br/>
Ans: [] yes, -> yes, * yes, ?: No

**Which of the following is an invalid visibility label while inheriting a class**  <br/>
Ans: friend

**Which one of the following is correct about the statements given below?**<br/>
**All function calls are resolved at compile-time in Procedure Oriented Programming.**<br/>
**All function calls are resolved at compile-time in OOPS.**<br/>
Ans: Only I is correct.

**What will happen if a class is not having any name?**<br/>
Ans: It cannot have a destructor. It cannot have a constructor.

**Which of the following is used to make an abstract class**<br/>
Ans: Making at least one member function as pure virtual function

**Which one of the following options is correct**<br/>
Ans: Friend function can access public/protected/private data members of the class
**Choose the respective delete operator usage for the expression ‘ptr=new int[100]’.** <br/>
Ans: delete[] ptr;<br/>

**Runtime polymorphism is done using.** <br/>
Ans: Virtual functions gives the ability to override the functionality of base class into the derived class. Hence achieving dynamic/runtime polymorphism.<br/>

**Which of the following approach is adapted by C++?** <br/>
Ans: Object oriented language such as C++/java/python uses **bottom up approach** where each object is identified first.<br/>

**Which of the following is not the member of class?** <br/>
Ans: Friend function<br/>

**Which of the following is correct about the statements given below?** <br/>
*All operators can be overloaded in C++.* <br/>
*We can change the basic meaning of an operator in C++.*<br/>
Ans: Both I and II are false<br/>

**Which one of the following is the correct way to declare a pure virtual function** <br/>
Ans: virtual void Display(void) = 0;<br/>

**Which of the following statements regarding inline functions is correct?** <br/>
Ans: It speeds up execution. It increases the code size.<br/>

**In which of the following a virtual call is resolved at the time of compilation?** <br/>
Ans: From inside the destructor. From inside the constructor.<br/>

**Which of the following operators cannot be overloaded?** <br/>
Ans: [] yes, -> yes, * yes, ?: No<br/>

**Which of the following is an invalid visibility label while inheriting a class**  <br/>
Ans: friend<br/>

**Which one of the following is correct about the statements given below?**<br/>
*All function calls are resolved at compile-time in Procedure Oriented Programming.*<br/>
*All function calls are resolved at compile-time in OOPS.*<br/>
Ans: Only I is correct.<br/>

**What will happen if a class is not having any name?**<br/>
Ans: It cannot have a destructor. It cannot have a constructor.<br/>

**Which of the following is used to make an abstract class**<br/>
Ans: Making at least one member function as pure virtual function<br/>

**Which one of the following options is correct**<br/>
Ans: Friend function can access public/protected/private data members of the class<br/>

**Which of the following cannot be declared as virtual?**<br/>
Ans: Constructor and Data Members<br/>

**Where the default value of parameter have to be specified?**<br/>
Ans: Function prototype<br/>

**Which of the following means "The use of an object of one class in definition of another class"?** <br/>
Ans: Composition<br/>

**Which of the following statement is correct with respect to the use of friend keyword inside a class?** <br/>
Ans: A class may be declared as a friend.<br/>

**Which of the following statement is correct regarding destructor of base class?** <br/>
Ans: Destructor of base class should always be virtual.<br/>

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
Ans: 65, as the union variables share common memory for all its elements, x gets ‘A’ whose ASCII value is 65 and is printed.<br/>

**Which of the following statement is correct?**
Which of the following statement is correct? <br/>

**Which of the following statements is correct?**
*We can return a global variable by reference.*
*We cannot return a local variable by reference.*
Only 2 is correct
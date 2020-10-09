Table of Contents
=================
  * [Pointer, Referernce](#Pointer_Referernce)

## Pointer_Referernce
#### Pointer (\*) and Address-of Operator (&)
The declaration of pointers follows this syntax: <br/>
&nbsp;type \* name; <br/>
where type is the data type pointed to by the pointer. <br/>
This type is not the type of the pointer itself, but the type of the data the pointer points to.
```
int* ptr = nullptr; // Declaring pointer
int x = 5;
ptr = &x; // The unary address-of operator ( & ) takes the address of its operand
```

#### Dereference operator (\*)
pointer: a variable which stores the address of another variable. <br/>
dereference:  get the value a pointer point to 
```
int x = 5;
int* ptr = &x; // ptr store the address of x
int y = *ptr; // Dereferencing the pointer, y = the value store at the address of ptr point to (i.e., 5)
```

#### Pass by value, Pass by adress, Pass by reference (c++ only)
```
void increment(int a) { a = a + 1 };&nbsp;// Pass by value, only change the copy of a, do not affect original a
void increment(int* pa) { *pa = *pa + 1 };&nbsp;// Pass by address, change the value at memory of a, will affect original a
void increment(int& a) { a = a + 1 };&nbsp;// Pass by reference, new variable will point to the same object, will affect original a
```


- [Data types](#data-types)

- [Pointers](#pointers)

- [Memory management](#memory-management)

- [Structures](#structures)

- [Class](#class)

- [Others](#others)
  + Loops
  + Enums
  + Includes
  + Namespace
  + Makefiles
  + Passing args


# Data types

```
Byte = 8bits
00000001 1 = 1                    Hexadecimal
00000010 2 = 2                    1-9 then 
00000100 3 = 4                    A = 10  0xA  1010
00001000 4 = 8                    B = 11  0xB  1011
00010000 5 = 16                   C = 12  0xC  1100    
00100000 6 = 32                   D = 13  0xD  1101
01000000 7 = 64                   E = 14  0xE  1110
10000000 8 = 128                  B = 15  0xF  1111

Char      = 1 byte
short int = 2 bytes
int       = 2 or 4 bytes
long int  = 4 bytes
```
## Arrays and Vectors
- **Array** Needs to set size. Do not keep track of their size as they are a pointer to a designated memory space of assigned size `dataType arrayName[arraySize];` Handle with care when passed to a function as what is passed is just a pointer to first address.  
- **Templatized Array** 
- **Vector** Need to #include <vector> with C++11| Better and simplier as they keep track of their own size. Can also be expanded in size or values can be "popped" from it. Check size of vector by vector_name.size()
	`std::vector<int> V; V.push_back(1); /* Created empty int vector and then added integer 1/*`


### Casting
```(type) varialbe```

Casting to unsigned makes it always positive

Casting to shorter suze - remaining bits on the left are discarded

## Setting | Clearing bits

```(1<<5) = 32 = 00100000```  
Setting bits with OR  ```bits |= (1<<5) /* sets bit 5 /*```
Clearing bits with AND  ```bits &= ~(1<<5) /* clears bit 5 /*```
```
declared structure time
struct{
	unsigned seconds :5;
	unsigned minutes :6;
	unsigned hours   :5;
}time;

time >> 5 
time is short int therefore 0xFFFF
0x3F = 0011 1111 & with 0x3F
```

---------------------------------------------------------
# Pointers

variable that stores the address of another variable

```
int* p;  /* declare pointer to integer */

p = &c;  /* initialize pointer with address of c */

temp = *p /* deference pointer, gives value stored in address */

int arr[10];
int(*p)[10] = &arr;

char function(void);
char(*p)(void) = &function; /* pointer to a fucntion with no args and returns char */

struct abc{
	int a;
	int b;
} var;
struc abc *p = &var;  /* pointer to address of structure */

int A[10]; /* address 0x2000 */  with all elements = 0xA
int C[10]; /* address 0x3000 */  with all elements = 0xB

int*p=&(A+5)
temp = *p
```
--- Function Pointers ---


----------------------------------
# Memory management

Object: region of memory that can be examined and stored into | kind of variables

Object attributes:

- Type
- Name
- Value
- Address
- Scope
- Lifetime
  
### Scope 
extern int a; /* has been declared in other file */

static int y; /* can only be accessed within this file */


### Lifetime
Created -> initialized -> Used -> Destroyed

## Memory location 
_(RAM)_ **Stack** Memory stored stacking area predefined size. Fast because its just stacking over previous occupied space.
-> reclaimed by program automatic (implicit)

_(RAM)_ **Heap** - no pattern how memory is stored -> reclaimed by programer || malloc (new) 
Responsability of Programmer to clear memory.

----------
# Structures
Compatible with C and defined in C++ before C++11. 
Elements in Structures are defined as **public**
Normally used for simple tasks related to data types, ex: Bitfields
```
struct test{
	int a;
	int b;
};

struct test one;
struct test one={1,2};
```

# Class 
Really similar to structures but elements are defined as **private**

**Inheritance** - all that is public: But while inheriting it can be done public, protected or private for coming child classes.

- Private: Only current class has access to elements
- Protected: Current class and subclasses
- Public: Any class can access public elements

**Constructor** Everytime an instance of the class is created, Constructor function is called. This can be used to initialize values or keep track of how many instances exist. Declared withing the class as a function having the same name. By default constuctor does nothing.

**Desctuctor** Called when an instance is out of scope hence removed from memory.

**Polymorphism**: same fucntion can act differently in two different scenario. Use Virtual while replacing parent methods.

**Friends class**

--------
# Others
### Lops
- for: simple loop, if condition is met. Has an initialization condition --> condition check > increment 
- while: does not have initialization condition
- do, while: ensures at least one run of the code


### Enums
Easy way to construct defined macros for consecutive and related values.
```
enum ENUM { ONE=1, TWO, THREE, FIVE=5};
/* ONE=1, TWO=2, THREE=3, FIVE=5 */
```

### Inclusion
- ```#include <file>``` searches the system include path
- `#include "file"` searches the local directory

For header files use: `#pragma once`
`#ifndef MACRO
#define MACRO
...
#endif`

### Namespace
Tag for a package to make clear to which library an element is referring to. Can be ignored by setting Ex. `using namespace std;` though is not recommended as this namespaces make refferences clearer.
	
### Main
Basic main serves as the initial point of any program. It is important to define one and by default this is done by the main fucntion.
On it's basic form takes no argument but returns an integer (commonly 0 to refer that program as ran and finished without problems).
```int main(){ return0;} ```
It can also be that we want to run the program while passing arguments from the start, that is done by passing these arguments to the main function. It stores the amount in int argc and stores the values in an array argv)

```
int main(int argc, char** argv) {
    std::cout << "Have " << argc << " arguments:" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
}	
```
					 
### Makefiles
Makefiles are scripts that allow compilation of multiple cpp files, declaring dependencies.
from file.cpp ->  file.o  -> app.out
Called with command `make` and the objective is to create an output executable file.
	
```
target: dependencies
	action
```

## Passing arguments to functions
- Passing by **VALUE**: Parameter value copies to another variable thus modifications done to this variable are not present in original variable.
	
`int var=5;
sum_one(var); // function returns var++
cout<< var; // prints value of 5
`
	
- Passing by **REFERENCE**: Passes actual paramenter to fucntion, this is done by passing the address where variable is stored and dereferencing its value.

`int var=5;
sum_one(&var); // function returns *var++
cout<< var; // prints value of 5
`

- Passing by **POINTER**: Mostly done by passing arrays. Passes a pointer to the first address of the array.

	
## Notes:
- Handle Branching with care as it could be expensive for some compilers: *"A branch is an instruction in a computer program that can cause a computer to begin executing a different instruction sequence and thus deviate from its default behavior of executing instructions in order"*.


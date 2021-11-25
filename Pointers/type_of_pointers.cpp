#include<stdio.h>
#include<iostream>

int i; // integer declaration
int * p; // pointer to int
int *(p1);
int a[1]; // array on integers
int f(); // function declaration

int ** pp; // pointer to integer pointer
int (*pa)[1]; // pointer to array of integers
int (*pf)(); // pointer to function that returns integer

int *ap[1];  // array of pointers to integers
int aa[1][1]; // array of arrays of integers
// int af[1]();  array of functions returning integer (IL)

int * fp(); // function retrning an int pointer
// int fa()[1]; // function returning an array of integers (IL)
// int ff()();  function returning a function returning an integer (IL)
int ***ppp; // pointer to pointer to int pointer
int **(ppa)[1]; // pointer to pointer to array of int
int (**ppa2)[1];

int **(ppf)(); // pointer to pointer to function that returns int
int *paa[1][1]; // pointer to array of arrays of ints
int **app[1]; // array of pointers to int pointers

int main()
{
    int var1= 5, var2 =10; 
    p=&var1;
    p1=&var2;
    std::cout << "pointer to var1: " << *p << std::endl;
    std::cout << "pointer to var2: " << *p1 << std::endl;
    
    char array[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    char* cp = array;
    char (*cp1)[16]; // pointer to array of char
    cp1=&array;
    int* y = (int*) array;
    short* z = (short*)array;
    for(int i=0; i<4;i++)
    {
        printf("pointer to int pointing at first element y=0x%x \n", *y);
        y++;
        
        printf("pointer to char pointing to first element cp=%d \n", *cp);
        cp++;
        
        std::cout<< "pointer to char array of 16 elements" << cp1 << std::endl;
        //printf("cp1=%c \n", *cp1);
        cp1++;
    }
    return 0;
}

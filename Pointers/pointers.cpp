/* Pointers are variables that hold the address of other variables */

#include <iostream>

using namespace std;

// function declarations
int addition(int a, int b);
int subtraction(int a, int b);
int operation(int x, int y, int( * call_function)(int, int));
void pointer_to_function();
void pointer_arithmetics();

// ---  MAIN  ---
int main() {

    pointer_arithmetics();
    pointer_to_function();
}


/* Pointer arithmetics
 * 
 * Important is to show that p++ points to one block of memory
 * ahead, depending on the type pointed to.
 */

void pointer_arithmetics() {
    /* pointer to array */
    int numbers[5];
    int * p;
    p = numbers; // pointer to array
    * p = 10; // assign value to first location in array

    p++; // now points one "int" ahead arr[1]
    * p = 20;

    p = & numbers[2]; // Get address of array[2]
    * p = 30;

    p = numbers + 3; // pointer set to address of array[0 + 3]
    * p = 40;

    p = numbers; // increment the pointer to 4 integer spaces
    *(p + 4) = 50;

    cout << "Pointer arithmetics: " << endl;
    for (int n = 0; n < 5; n++)
        cout << numbers[n] << endl;
}

/* Pointer to functions
 * 
 * Serve to be passed as arguments to another function
 * Name of the function is enclosed in parenthesis 
 * Input parameters should also be defined in pointer
 */
int addition(int a, int b) {
    return (a + b);
}

int subtraction(int a, int b) {
    return (a - b);
}

// call_function is the pointer to function
int operation(int x, int y, int( * call_function)(int, int)) {
    int result;
    result = ( * call_function)(x, y); // dereference pointer to call function
    return (result);
}

void pointer_to_function() {
    int num, total;
    // Create pointer minus to function substraction
    int( * minus)(int, int) = subtraction;

    // Passing function as argument
    num = operation(7, 5, addition); // 7+5=12
    total = operation(20, num, minus); // 20-12=8
    cout << "Pointer to function result is: " << total << endl;
}

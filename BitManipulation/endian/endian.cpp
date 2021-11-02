#include <iostream>
using namespace std;

/* Out = 1, little-Endian 
   otherwise,  big-endian */

int endian() {
	int var = 1;
	char *ptr;
    // Char pointer to integer
	ptr = (char *)&var;
    // Derreference value of pointer
	return (*ptr);
}

int main()
{
	if(endian()) 
		cout << "Little Endian\n";
	else
		cout << "Big Endian\n";
}

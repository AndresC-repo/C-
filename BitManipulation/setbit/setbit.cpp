/*
 * bits are set by using | (OR) 
 * bits are removed by & (AND)
 * 1 << index moves the one to desired position
 * ~ negation symbol ~1010 -> 0101
 */
#include <iostream>

using namespace std;

// Bitwise print of number
bool getBit(int input, int index)
{
	return ( (input & (1 << index) ) > 0);
}

int setBit(int input, int index, bool set)
{
	if(set)
        // set bit at index
		return (input | (1 << index)) ;	
	else {
        // clear bit at index
		int mask = ~(1 << index);
        return input & mask;
	}
}

int main()
{
	int num, index;

	num = 16;
    cout << "Input an integer: " << endl;
    // example num = 16  is 00010000
    cin >> num;
    
    // print number in bin
	cout << "Input" << endl;
	for (int i = 7; i >= 0; i--) 
		cout << getBit(num,i) << " ";
	cout << endl;

	/* set bit */
    cout << "Input an index to set bit: " << endl;
    cin >> index;
	cout << "Setting " << index << "-th bit" << endl;
	num = setBit(num, index, true);
	for (int i = 7; i >= 0; i--) 
		cout << getBit(num,i) << " ";
	cout << endl;

	/* clear bit */
    cout << "Input an index to clear bit: " << endl;
    cin >> index;
	cout << "Clearing " << index << "-th bit" << endl;
	num = setBit(num, index, false);
	for (int i = 7; i >= 0; i--) 
		cout << getBit(num,i) << " ";
	cout << endl;

	return 0;
}

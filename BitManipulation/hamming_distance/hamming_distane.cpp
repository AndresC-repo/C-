#include <iostream>

int hamming(unsigned int x, unsigned int y)
{
    int distance = 0;
    // XOR gets the bits that are different between x and y
    unsigned int val = x ^ y;
    // while there are bits in val count bit distance
    while(val) {
       distance++;
       val &= val - 1;
    }
    return distance;
}

int main()
{
    /* 16 = 10000
       31 = 11111 */
   	int x;
	int y;   
    std::cout << "Input two numbers" << std::endl;
    std::cin >> x;
	std::cin >> y;
    std::cout << "Distance is: " << hamming(x, y) <<std::endl;    // = 4
    return 0;
}

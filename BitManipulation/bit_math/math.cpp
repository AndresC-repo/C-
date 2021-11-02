#include <stdio.h>
#include <iostream>

/* CHAR_BIT as 8 meaning the amout of bits in a byte
 * 
 * Remember two's complement for ussing only summations
 * to also substract numbers
 */
 
static const char CHAR_BIT = 8;

void abs()
{
	/* Get the absoulute value of given number */
	int var;
	std::cin >> var;
	unsigned int result;
	
	// Get sign bit
	int const mask = var >> sizeof(int) * CHAR_BIT - 1;
	
	// Add the mask (2's compliment fot negative numbers) and do XOR 
	result = (var + mask) ^ mask;
	
	std::cout << result <<std::endl;
}

void min_max()
{
	int x;
	int y;   
	std::cin >> x;
	std::cin >> y;

	int result;
	
	// x < y) ? x : y avoiding branching 
	result = y ^ ((x ^ y) & -(x < y)); // min(x, y)
	std::cout << "min" <<std::endl;
	std::cout << result <<std::endl;
	result = x ^ ((x ^ y) & -(x < y)); // max(x, y)
	std::cout << "max" <<std::endl;
	std::cout << result <<std::endl;

}
int main()
{
	abs();
	min_max();
	return 0;
}



#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>

using namespace std;

/*
Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
*/

int hammingWeight(uint32_t n) {
	bitset<32> bits{ n };
	return bits.count();
}
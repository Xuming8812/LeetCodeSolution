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
Reverse bits of a given 32 bits unsigned integer.
*/

uint32_t reverseBits(uint32_t n) {
	bitset<32> store{ n };

	stringstream ss;

	for (int i{ 0 }; i < 32; i++)
	{
		ss << store[i];
	}

	bitset<32> reverse{ ss.str() };

	uint32_t result = static_cast<uint32_t>(reverse.to_ulong());

	return result;
}
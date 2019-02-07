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
Given a non negative integer number num. For every numbers i in the range 0 ¡Ü i ¡Ü num 
calculate the number of 1's in their binary representation and return them as an array.
*/

vector<int> countBits(int num) {
	vector<int> result(num + 1);
	result[0] = 0;

	for (int i = 1; i <= num; ++i)
	{
		if (i % 2 == 0)
		{
			result[i] = result[i / 2];
		}
		else
		{
			result[i] = result[i - 1] + 1;
		}

	}

	return result;
}
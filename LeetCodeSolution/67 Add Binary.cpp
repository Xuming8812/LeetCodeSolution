#include<vector>
#include<map>
#include<string>
#include<queue>

using namespace std;

/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.
*/

string addBinary(string a, string b)
{
	//use two pointer to point to string a and b`s current bit
	int i = a.size() - 1, j = b.size() - 1;

	int carry = 0;
	string result;

	while (i >= 0 || j >= 0)
	{
		//default value for bitA and bitB are zeros
		int bitA = 0, bitB = 0;
		if (i >= 0)
		{
			bitA = a[i] - '0';
			i--;
		}
		if (j >= 0)
		{
			bitB = b[j] - '0';
			j--;
		}

		//sum all things up
		int sum = bitA + bitB + carry;
		//update sum and carry
		carry = sum / 2;
		sum = sum % 2;
		//update the result string
		result = to_string(sum) + result;
	}

	//if the carry is not 0, add 1 in front of the string
	if (carry == 1)
	{
		result = "1" + result;
	}

	return result;
}
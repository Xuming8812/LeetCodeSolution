#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.
*/

vector<int> plusOne(vector<int>& digits) {

	vector<int> result;

	int digit{ 0 }, carry{ 0 };

	for (int i{ digits.size() - 1 }; i >= 0; --i) {
		if (i == digits.size() - 1) {
			digit = digits[i] + 1;
		}
		else {
			digit = digits[i] + carry;
		}

		carry = digit / 10;
		digit = digit % 10;

		result.push_back(digit);
	}

	if (carry == 1) {
		result.push_back(1);
	}

	vector<int> resultReverse(result.size());

	for (size_t i{ 0 }; i < result.size(); ++i) {
		resultReverse[i] = result[result.size() - 1 - i];
	}

	return resultReverse;
}
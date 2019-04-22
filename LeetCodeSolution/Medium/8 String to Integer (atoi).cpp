#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.
*/


//whether a char is a digit
bool isNum(char c)
{
	if (c >= '0' && c <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int myAtoi(string str) {

	long result{ 0 };
	int length = str.size();
	int index{ 0 };
	bool isPositive{ true };

	//neglect whitespace in front       
	while (index < length && str[index] == ' ') {
		index++;
	}

	if (index == length) {
		return 0;
	}

	//get sign
	if (str[index] == '-') {
		isPositive = false;
		index++;
	}
	else if (str[index] == '+') {
		isPositive = true;
		index++;
	}

	//begin get number
	while (isNum(str[index])) {
		result = result * 10 + str[index] - '0';

		if (isPositive && result > INT_MAX) {
			return INT_MAX;
		}
		else if (!isPositive && -result < INT_MIN) {
			return INT_MIN;
		}

		index++;
	}

	result = isPositive ? result : -result;

	return static_cast<int>(result);
}
#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

/*
Count the number of prime numbers less than a non-negative number, n.

1.     1
2.     11
3.     21
4.     1211
5.     111221

Given an integer n where 1 ¡Ü n ¡Ü 30, generate the nth term of the count-and-say sequence.
*/

string countAndSay(int n) {
	if (n <= 1)
	{
		return "1";
	}

	//set the initial result value
	string result{ "1" };


	//loop for n times
	for (int i = 1; i < n; i++)
	{
		//set the current char and its count
		char current = result[0];
		int count{ 1 };
		string temp{""};
		//loop all characters in the result string to count
		for (int j = 1; j < result.size(); j++)
		{
			//if characters equals to current char, count ++
			if (result[j] == current)
			{
				count++;
			}
			else
			{
				//save current count and current char
				temp += to_string(count) + string(1, current);
				//reset the current char and count for new count
				current = result[j];
				count = 1;
			}
		}

		//add final count result to result string
		temp += to_string(count) + string(1, current);

		result = temp;
	}

	return result;
}

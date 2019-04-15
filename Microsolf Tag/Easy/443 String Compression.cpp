#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.
*/

//inplace version
int compress(vector<char>& chars)
{
	int count = 0;
	int index = 0;
	//loop all characters
	for (int i = 0; i < chars.size(); i++)
	{
		//add count
		count++;
		//if last char or different char from previous
		if (i == chars.size() - 1 || chars[i] != chars[i + 1])
		{
			//move the pointer
			chars[index++] = chars[i];
			//if the count is bigger than 1
			if (count != 1)
			{
				
				for (char ch : to_string(count))
				{
					chars[index++] = ch;

				}
			}

			//set new start 
			count = 0;
		}

	}
	return index;
}

/**
 * @param originalString: a string
 * @return: a compressed string
 */
string compress(string &originalString) {
	// write your code here

	//initial result string
	string result{ "" };
	//corner condition
	if (originalString.empty()) {
		return result;
	}
	//set the current char and current number of same chars
	char current = originalString[0];
	int count{ 1 };

	//loop other chars in the string
	for (int i = 1; i < originalString.size(); i++) {
		//same with the current char
		if (originalString[i] == current) {
			count++;
		}
		//different char
		else {
			//append the current result in string result
			result = result + string(1, current) + to_string(count);

			//reset current char and number
			current = originalString[i];
			count = 1;
		}
	}
	//save the last result
	result = result + string(1, current) + to_string(count);
	//see which string is longer
	if (result.size() < originalString.size()) {
		return result;
	}
	else {
		return originalString;
	}
}
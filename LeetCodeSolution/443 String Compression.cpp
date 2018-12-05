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


/*
int compress(vector<char>& chars)
{
	if (chars.empty())
	{
		return 0;
	}

	if (chars.size() == 1)
	{
		return 1;
	}

	sort(chars.begin(), chars.end());

	vector<int> count(127);

	for (size_t i{ 0 }; i < chars.size(); ++i)
	{
		count[chars[i]]++;
	}

	int result{ 0 };

	for (size_t i{ 0 }; i < count.size(); ++i)
	{
		if (count[i] > 0)
		{
			chars[result++] = static_cast<char>(i);

			if (count[i] == 1)
			{
				continue;
			}
			else
			{
				int thousand = count[i] / 1000;
				if (thousand)
				{
					chars[result++] = '0' + thousand;
				}
				int hundred = (count[i] - 1000 * thousand) / 100;
				if (hundred)
				{
					chars[result++] = '0' + hundred;
				}
				int ten = (count[i] - 1000 * thousand - 100 * hundred) / 10;
				if (ten)
				{
					chars[result++] = '0' + ten;
				}
				int one = count[i] % 10;
				if (one)
				{
					chars[result++] = '0' + one;
				}
			}
		}
	}

	return result;

}
*/
//inplace version
int compress(vector<char>& chars)
{
	int count = 0;
	int index = 0;
	for (int i = 0; i < chars.size(); i++)
	{
		count++;
		if (i == chars.size() - 1 || chars[i] != chars[i + 1])
		{

			chars[index++] = chars[i];
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
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.
*/

/*
int countSegments(string s)
{
	stringstream ss;
	ss << s;
	string temp;
	int result{ 0 };
	while (ss >> temp)
	{
		result++;
	}
	return result;
}
*/


//second version to find non-space char
int countSegments(string s) {
	int len = s.length(), counter = 0, i = 0;
	while (i < len)
	{
		// find the non-space i 
		while (s[i] == ' ' && i < len) i++;  
		if (i < len) counter++;
		// find the next space i
		while (s[i] != ' ' && i < len) i++;  
	}
	return counter;
}
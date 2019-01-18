#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;


/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

string intToRoman(int num) {

	vector<int> intDict{ 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	vector<string> stringDict{ "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };

	string result;

	while (num != 0) {
		for (int i = 12; i >= 0; i--) {
			if (num >= intDict[i])
			{
				result += stringDict[i];
				num -= intDict[i];
				break;
			}
		}
	}


	return result;

}
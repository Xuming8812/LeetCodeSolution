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
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
*/

bool isPowerOfFour(int num) {
	if (num == 1) {
		return true;
	}
	if (num % 4 != 0 || num == 0) {
		return false;
	}

	return isPowerOfFour(num / 4);
}

bool isPowerOfFour(int num) {

	double actualResult = log(num) / log(4);

	int result = static_cast<int>(actualResult);

	if (abs(actualResult - result) < 1e-10){
		return true;
	}
	else{
		return false;
	}
}
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Implement pow(x, n), which calculates x raised to the power n (xn).
*/

double myPow(double x, int n) {
	if (x == 0) {
		return 0;
	}

	if (n == 0) {
		return 1;
	}

	double half = myPow(x, n / 2);

	if (n % 2 > 0 ) {
		return half * half * x;
	}
	else if(n%2 == 0){
		return half * half;
	}
	else {
		return half * half * (1/x);
	}
}
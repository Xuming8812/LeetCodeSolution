#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
*/

vector<vector<int>> result;

void combineHelper(int n, int k, int start, vector<int> chosen) {
	if (k == 0) {
		result.push_back(chosen);
		return;
	}

	for (int i = start; i <= n; i++) {

		chosen.push_back(i);            //choose
		combineHelper(n, k - 1, i + 1, chosen);    //explore
		chosen.pop_back();              //unchoose   


	/*
	auto pos =  find(chosen.begin(),chosen.end(),i);
	if(pos == chosen.end()){
		chosen.push_back(i);            //choose
		combineHelper(n,k-1,i+1,chosen);    //explore
		chosen.pop_back();              //unchoose
	}
	*/
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<int> chosen;

	combineHelper(n, k, 1, chosen);

	return result;
}
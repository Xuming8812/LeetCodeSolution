#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
*/

void restoreIpAddressesHelper(vector<string>& result, vector<string> ip, string s, int index) {
	if (index == s.size()) {
		if (ip.size() == 4) {
			result.push_back(ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3]);
		}

		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (index + i > s.size()) break;

		if (i > 1 && s[index] == '0') break;

		if (3 * (4 - ip.size()) < s.size() - index) break;

		string temp = s.substr(index, i);

		int num = stoi(temp);

		if (num <= 255 && num >= 0) {
			ip.push_back(temp);

			restoreIpAddressesHelper(result, ip, s, index + i);

			ip.pop_back();
		}
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> result;
	vector<string> ip;

	restoreIpAddressesHelper(result, ip, s, 0);

	return result;
}
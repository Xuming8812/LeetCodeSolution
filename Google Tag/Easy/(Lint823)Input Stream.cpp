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
Give two input stream inputA and inputB, which have Backspace. 
If the final result of the two input streams are equal, output YES, otherwise output NO.
*/

/**
 * @param inputA: Input stream A
 * @param inputB: Input stream B
 * @return: The answer
 */
string inputStream(string &inputA, string &inputB) {
    //use two stacks to store the chars
    stack<char> resA;
    stack<char> resB;
    //store stream A
    for(int i = 0; i < inputA.length(); ++i) {
        if(inputA[i] != '<') {
            resA.push(inputA[i]);
        } 
        else if(!resA.empty()) {
            resA.pop();
        }
    }
    //store stream B
    for(int i = 0; i < inputB.length(); ++i) {
        if(inputB[i] != '<') {
            resB.push(inputB[i]);
        } 
        else if(!resB.empty()) {
            resB.pop();
        }
    }
    //compare each char in both stacks
    while(!resA.empty() && !resB.empty()) {
        if(resA.top() != resB.top()) {
            return "NO";
        }
        resA.pop();
        resB.pop();
    }
    //if there are chars left in the either stack
    if(!resA.empty() || !resB.empty()) {
        return "NO";
    }
    return "YES";
}
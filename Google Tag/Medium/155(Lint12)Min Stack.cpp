#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Implement a stack with following functions:

push(val) push val into the stack
pop() pop the top element and return it
min() return the smallest number in the stack
All above should be in O(1) cost.
*/


class MinStack {
public:
    MinStack() {
        // do intialization if necessary
        _minStack.push({INT_MAX,INT_MAX});
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {

        int currentMin = _minStack.empty() ? INT_MAX : _minStack.top().second;
        
        currentMin = std::min(number,currentMin);
        
        _minStack.push({number,currentMin});
        
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int result = _minStack.top().first;
        _minStack.pop();
        
        return result;
    }

    /*
     * @return: An integer
     */
    int min() {
        // write your code here

        if(!_minStack.empty()){
            return _minStack.top().second;
        }
        
        return -1;
    }
    //use a stack to store a num and current min value so far
    stack<pair<int,int>> _minStack;
};
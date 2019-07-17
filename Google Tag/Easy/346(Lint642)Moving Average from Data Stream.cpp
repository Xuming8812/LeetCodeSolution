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
Given two rectangles, find if the given two rectangles overlap or not.
*/  

class MovingAverage {
public:
    /*
    * @param size: An integer
    */MovingAverage(int size) {
        // do intialization if necessary
        size_ = size;
        sum = 0;    
    }

    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        // write your code here
        store.push(val);
        sum+=val;
        
        if(store.size()>size_){
            int temp = store.front();
            store.pop();
            sum -=temp;
        }
        
        return sum/store.size();
    }
    
private:
    //use a queue to store the stream
    queue<int> store;
    int size_;
    double sum;
};
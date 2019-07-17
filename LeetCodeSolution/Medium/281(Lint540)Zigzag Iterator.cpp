#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<queue>
#include<sstream>
#include<set>

using namespace std;


/*
Given two 1d vectors, implement an iterator to return their elements alternately.
*/


class ZigzagIterator {
public:
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        // do intialization if necessary
        int index=0;
        int flag = 0;
        while(index<v1.size()&&index<v2.size()){
            if(flag%2==0){
                store.push(v1[index]);
            }
            else{
                store.push(v2[index]);
                index++;
            }
            
            flag++;
        }
        
        while(index<v1.size()){
            store.push(v1[index++]);
        }
        
        while(index<v2.size()){
            store.push(v2[index++]);
        }
    }

    /*
     * @return: An integer
     */
    int next() {
        // write your code here
        int result = store.front();
        
        store.pop();
        
        return result;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        // write your code here
        return !store.empty();
    }
private:
    queue<int> store;
};
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Given two integer arrays a and b,please find the number in a with the minimal distance between 
corresponding value in b (the distance between two numbers means the absolute value of two numbers), 
if there are several numbers in a have same distance between b[i],just output the smallest number.
Finally, you should output an array of length b.length to represent the answer.
*/


/**
 * @param a: array a
 * @param b: the query array
 * @return: Output an array of length `b.length` to represent the answer
 */
vector<int> minimalDistance(vector<int> &a, vector<int> &b) {
    // Write your code here 
    vector<int> result;
    
    if(a.empty() || b.empty()){
        return result;
    }
    
    sort(a.begin(),a.end());
    
    for(int i = 0;i<b.size();i++){
        int temp = getNearest(a,b[i]);
        
        result.push_back(temp);
    }
    
    return result;
}

//helper function to find the closest neighbor
int getNearest(vector<int> &a, int num){
    int left = 0;
    int right = a.size()-1;
    
    while(left<right){
        int mid = left + (right-left)/2;
        
        if(a[mid]==num){
            return num;
        }
        
        if(a[mid]>num){
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    int result = a[left];
    
    if(left>0){
        int candidate = a[left-1];
        if(num - candidate<=result-num){
            result = candidate;
        }
    }
    
    return result;
}
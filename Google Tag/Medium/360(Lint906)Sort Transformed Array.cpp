#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_set>
#include<bitset>

using namespace std;

/*
Given a sorted array of integers nums and integer values a, b and c. Apply a quadratic function of the form f(x)=ax^2+bx+cf(x)=ax^2+bx+c to each element xx in the array.

The returned array must be in sorted order
*/

/**
 * @param nums: a sorted array
 * @param a: 
 * @param b: 
 * @param c: 
 * @return: a sorted array
 */
vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    int length = nums.size();
    
    int left = 0, right = length - 1;
    vector<int> result(length);
    
    //the index of result
    
    /*
    当a>0，说明两端的值比中间的值大，那么此时我们从结果res后往前填数，用两个指针分别指向nums数组的开头和结尾，指向的两个数就是抛物线两端的数，
    将它们之中较大的数先存入res的末尾，然后指针向中间移，重复比较过程，直到把res都填满。
    当a<0，说明两端的值比中间的小，那么我们从res的前面往后填，用两个指针分别指向nums数组的开头和结尾，指向的两个数就是抛物线两端的数，
    将它们之中较小的数先存入res的开头，然后指针向中间移，重复比较过程，直到把res都填满。
    当a=0，函数是单调递增或递减的，那么从前往后填和从后往前填都可以，我们可以将这种情况和a>0合并
    */
    int idx = a >= 0 ? length - 1 : 0;
    
    while (left <= right) {
        if (a >= 0) {
            result[idx--] = cal(nums[left], a, b, c) >= cal(nums[right], a, b, c) ? cal(nums[left++], a, b, c) : cal(nums[right--], a, b, c);
        } else {
            result[idx++] = cal(nums[left], a, b, c) >= cal(nums[right], a, b, c) ? cal(nums[right--], a, b, c) : cal(nums[left++], a, b, c);
        }
    }
    return result;
}

//calculate f(x)
int cal(int x, int a, int b, int c) {
    return a * x * x + b * x + c;
}
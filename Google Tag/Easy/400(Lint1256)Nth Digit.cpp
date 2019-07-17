#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;


/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
*/


/**
 * @param n: a positive integer
 * @return: the nth digit of the infinite integer sequence
 */
int findNthDigit(int n) {
    //len,当前是几位数，note that 9个1位数，90个2位数
    //cnt,多少个当前的位数
    //start当前几位数的第一个数，分别为1，10，100...
    long long len = 1, cnt = 9, start = 1;
    
    //decide the number of digit, the start number
    while (n > len * cnt) {
        n -= len * cnt;
        ++len;
        cnt *= 10;
        start *= 10;
    }
    //get the number
    start += (n - 1) / len;
    string t = to_string(start);
    //get the bit
    return t[(n - 1) % len] - '0';
}
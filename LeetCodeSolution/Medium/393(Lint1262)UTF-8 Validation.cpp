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
A character in UTF-8 can be from 1 to 4 bytes long, subjected to the following rules:

For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
Given an array of integers representing the data, return whether it is a valid UTF-8 encoding.
*/

/**
 * @param data: an array of integers
 * @return: whether it is a valid utf-8 encoding
 */
bool validUtf8(vector<int> &data) {
    // Write your code here
    //corner case
    if(data.empty()){
        return false;
    }
    //loop all strings
    for (int i = 0; i < data.size(); ++i){
        //if start with 0, continue
        if (data[i] < 0b10000000) {
            continue;
        } else {
            //count the number of leading 1
            int count = 0;
            
            bitset<8> bits(data[i]);
            
            for (int j = 7; j >= 4; --j) {
                if (bits[j]){
                    count++;
                }
                else{
                    break; 
                }
            }
            
            if(bits[7-count] != 0){
                return false;
            }
            //the condition that there is only one leading 1
            if (count == 1){
                return false; 
            }
            if(i+count-1>=data.size()){
                return false;
            }
            //loop all following bytes, should be 10xxxxxx
            for (int j = i + 1; j < i + count; ++j) {
                if (data[j] > 0b10111111 || data[j] < 0b10000000) return false;
            }
            
            i += count - 1;
        }
    }
    return true;
}
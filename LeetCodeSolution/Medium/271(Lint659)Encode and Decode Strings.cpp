#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<unordered_set>

using namespace std;

/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and 
is decoded back to the original list of strings.

Please implement encode and decode
*/

    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string result{};
        //encode
        for(auto item : strs){
            result=result + translate(item)+":;";
        }
        
        return result;
    }
    //helper function to encode, use :; '\n', if there is a ":", use "::" instead
    string translate(string input){
        string result{};
        
        for(int i{0};i<input.size();i++){
            if(input[i]!=':'){
                result = result+string(1,input[i]);
            }
            else{
                result = result + "::";
            }
        }
        
        return result;
    }
    
    
    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        int end{0};
        string temp{};
        
        vector<string> result;
        //loop all chars
        while(end<str.size()){
            
            if(str[end] !=':'){
                temp = temp+string(1,str[end++]);
            }
            else{
                //skip a ':'
                if(str[end+1] == ':'){
                    temp = temp+":";
                    end=end+2;
                }
                else if(str[end+1] == ';'){
                    //if is a return char
                    result.push_back(temp);
                    temp = "";
                    end = end + 2;
                }
                
            }
        }
        
        return result;
    }
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<set>

using namespace std;


/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. 
There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are valid. "1:34", "12:9" are invalid.
*/

/**
 * @param time: the given time
 * @return: the next closest time
 */
string nextClosestTime(string &time) {
    // write your code here
    
    //save char existing in the given time
    set<char>digits;
    for(int i=0;i<time.size();i++){
        digits.insert(time[i]);
    }
    
    string result;
    //get the minutes stands for the given time
    int givenTime = stoi(time.substr(0,2))*60 + stoi(time.substr(3));
    
    int distance = INT_MAX;
    
    //loop each minute in a day
    for(int i = 0;i<1440;i++){

        //get hour and minute
        int hour = i/60;
        int mins = i%60;
        //get the chars of current minute
        string temp = (hour<10?"0":"")+to_string(hour)+":"+(mins<10?"0":"")+to_string(mins);
        //see if the char is in given string
        bool isExsiting = true;
        
        for(auto ch : temp){
            if(digits.find(ch)==digits.end()){
                isExsiting = false;
                break;
            }
        }
        //find the closet time
        if(isExsiting){
            int tempDis=i>givenTime?(i-givenTime):(i-givenTime+1440);
            
            if(tempDis<distance){
                distance = tempDis;
                result = (hour<10?"0":"")+to_string(hour)+":"+(mins<10?"0":"")+to_string(mins);
            }
        }
    }
    
    return result;

}
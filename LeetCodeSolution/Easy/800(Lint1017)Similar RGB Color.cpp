#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>

using namespace std;

/*
In the following, every capital letter represents some hexadecimal digit from 0 to f.

The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand. For example, "#15c" is shorthand for the color "#1155cc".

Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.

Given the color "#ABCDEF", return a 7 character color that is most similar to #ABCDEF, 
and has a shorthand (that is, it can be represented as some "#XYZ")
*/

/**
 * @param color: the given color
 * @return: a 7 character color that is most similar to the given color
 */
string similarRGB(string &color) {
    // Write your code here

    //the value of each hex digit
    map<char, int> hex;
    //A-F
    for (int i = 0; i < 6; i++){
        hex['a' + i] = 10 + i;
    }
    //0~10
    for (int i = 0; i < 10; i++){
        hex['0' + i] = i;
    }
    //mapping from int to char
    vector<char> dict{ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
    //save the current RGB value
    vector<int> value;
    for (int i = 0; i < 3; i++){
        value.push_back(hex[color[2 * i + 1]] * 16 + hex[color[2 * i + 2]]);
    }

    string result{ "#" };

    for (int i = 0; i < 3; i++){
        //exactly can be written as 'XX'
        if (value[i] % 17 == 0){
            result = result + dict[value[i] / 17] + dict[value[i] / 17];
        }
        else{
            int index1 = value[i] / 17;
            int index2 = index1 + 1;
            //two candidates
            int result1 = hex[dict[index1]] * 16 + hex[dict[index1]];
            int result2 = hex[dict[index2]] * 16 + hex[dict[index2]];

            if (value[i]-result1 < result2-value[i]){
                result = result + dict[index1] + dict[index1];
            }
            else{
                result = result + dict[index2] + dict[index2];
            }
        }
    }

    return result;
}
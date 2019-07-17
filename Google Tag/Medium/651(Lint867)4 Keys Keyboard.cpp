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
Imagine you have a special keyboard with the following keys:

Key 1: (A): Print one 'A' on screen.
Key 2: (Ctrl-A): Select the whole screen.
Key 3: (Ctrl-C): Copy selection to buffer.
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.
Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.
*/



/**
 * @param N: an integer
 * @return: return an integer
 */
int maxA(int N){
    
    //initialize the dp vector
    vector<int> dp(N + 1, 0);
    
    //loop each N
    for (int i = 1; i <= N; i++){
        
        dp[i] = dp[i - 1] + 1;
        //max of CTRL C + CTRL V n times
        for (int j = 1; j + 2 < i; j++)
            dp[i] = max(dp[i], dp[i - 2 - j] * (j + 1));
    }

    return dp[N];
}
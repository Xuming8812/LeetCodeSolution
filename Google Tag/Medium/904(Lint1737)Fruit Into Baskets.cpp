#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


/*
In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: 
you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?
*/

/**
 * @param tree: the type of trees
 * @return: the max number of fruits collected
 */
int totalFruit(vector<int>& tree) {
    int result = 0;
    //use a map to store the type and its occurence
    map<int,int> count;
    //the left edge of the window
    int left=0;
    
    for(int right=0;right<tree.size();right++){
        
        count[tree[right]]++;
        //the window is too big,move left edge to the right until there are only two types in the window
        while(count.size()>2){
            count[tree[left]]--;
            //if one type is no longer existing in the window
            if(count[tree[left]]==0){
                count.erase(tree[left]);
            }
            
            left++;
        }
        
        result = max(right-left+1,result);
    }
    
    return result;
}
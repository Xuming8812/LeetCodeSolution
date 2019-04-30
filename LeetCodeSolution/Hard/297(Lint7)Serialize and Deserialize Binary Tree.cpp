#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>

using namespace std;

/*
Design an algorithm and write code to serialize and deserialize a binary tree. 
Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * This method will be invoked first, you should design your own algorithm 
 * to serialize a binary tree which denote by a root node to a string which
 * can be easily deserialized by your own "deserialize" method later.
 */
string serialize(TreeNode * root) {
    // write your code here
    
    string result;
    if(root == nullptr){
        return result;
    }
    
    vector<TreeNode*> store;
    store.push_back(root);
    
    for(int i = 0;i<store.size();i++){
        if(store[i]!=nullptr){
            store.push_back(store[i]->left);
            store.push_back(store[i]->right);
        }
    }
    
    while(!store.empty() && store.back()==nullptr){
        store.pop_back();
    }
    
    for(auto item : store){
        if(item == root){
            result += to_string(item->val);
        }
        else{
            if(item == nullptr){
                result +=(",#");
            }
            else{
                result +=(","+to_string(item->val));
            }
        }
    }
    
    return result;
}

/**
 * This method will be invoked second, the argument data is what exactly
 * you serialized at method "serialize", that means the data is not given by
 * system, it's given by your own serialize method. So the format of data is
 * designed by yourself, and deserialize it here as you serialize it in 
 * "serialize" method.
 */
TreeNode * deserialize(string &data) {
    // write your code here
    
    if(data.empty()||data == "#") return nullptr;
    
    vector<string> input = split(data);
    
    queue<TreeNode*> bfs;
    
    TreeNode* root = new TreeNode(stoi(input[0]));
    
    bfs.push(root);
    
    bool isLeft = true;
    
    for(int i = 1;i<input.size();i++){
        if(input[i]!="#"){
            TreeNode* current = new TreeNode(stoi(input[i]));
            if(isLeft){
                bfs.front()->left = current;
            }
            else{
                bfs.front()->right = current;
            }
            
            bfs.push(current);
        }
        
        if(!isLeft){
            bfs.pop();
        }
        
        isLeft = !isLeft;
        
    }
    
    return root;
    
    
}

vector<string> split(string data){
    stringstream ss;
    ss<<data;
    
    vector<string> result;
    string temp;
    
    while(getline(ss,temp,',')){
        result.push_back(temp);
    }
    
    return result;
}
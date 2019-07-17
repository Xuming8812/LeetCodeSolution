#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

/*
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. 
The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 10^4. 
Reconstruction means building a shortest common supersequence of the sequences in seqs 
(i.e., a shortest sequence so that all sequences in seqs are subsequences of it).
Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.
*/

/**
 * @param org: a permutation of the integers from 1 to n
 * @param seqs: a list of sequences
 * @return: true if it can be reconstructed only one or false
 */
bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
    //corner case
    if(seqs.empty() || org.empty()){
        return true;
    }
    
    
    // write your code here
    map<int,set<int>>graph;
    queue<int> bfs;
    vector<int> count(org.size()+1);

    //create the graph and save the reprequensis number of each node
    for(auto item : seqs){
        count[item[1]]++;
        graph[item[0]].insert(item[1]);
    }
    //the variable to store the number of possible orders
    int numOfSame = 0;
    //start with nodes with no reprequensis
    for(int i=1;i<=org.size();i++){
        if(count[i] == 0){
            bfs.push(i);
            numOfSame++;
        }   
    }
    
    if(numOfSame!=1){
        return false;
    }
    
    vector<int> result;
    //bfs
    while(!bfs.empty()){
        int current = bfs.front();
        bfs.pop();
        
        numOfSame = 0;
        
        result.push_back(current);
        //loop all neighbors
        for(auto item : graph[current]){
            count[item]--;
            if(count[item]==0){
                bfs.push(item);
                numOfSame++;
            }
        }
        
        if(numOfSame!=1){
            return false;
        }
    }
    
    if(result.size()!=org.size()){
        return false;
    }
    
    for(int i=0;i<org.size();i++){
        if(org[i]!=result[i]){
            return false;
        }
    }
    
    return true;
}
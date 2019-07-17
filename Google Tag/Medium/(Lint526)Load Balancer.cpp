#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


/*
Implement a load balancer for web servers. It provide the following functionality:

Add a new server to the cluster => add(server_id).
Remove a bad server from the cluster => remove(server_id).
Pick a server in the cluster randomly with equal probability => pick().
At beginning, the cluster is empty. When pick() is called you need to randomly return a server_id in the cluster.
*/


class LoadBalancer {
private:
    map<int, int> dict;
    vector<int> servers;
public:
    LoadBalancer() {
        // Initialize your data structure here.
    }

    // @param server_id add a new server to the cluster 
    // @return void
    void add(int server_id) {
        // Write your code here
        //push the server into vector and save its index in the hashmap
        int m = servers.size();
        dict[server_id] = m;
        servers.push_back(server_id);
    }

    // @param server_id server_id remove a bad server from the cluster
    // @return void
    void remove(int server_id) {
        // Write your code here
        //get the index of this server
        int index = dict[server_id];
        int m = servers.size();
        
        //replace this server by the last one
        dict[servers[m - 1]] = index;
        servers[index] = servers[m - 1];
        //remove the last one
        servers.pop_back();
        dict.erase(dict.find(server_id));
    }

    // @return pick a server in the cluster randomly with equal probability
    int pick() {
        // Write your code here
        int m = servers.size();
        // srand(time(0));
        //randomly pick one
        int index = rand() % m; 
        return servers[index];
    }
};
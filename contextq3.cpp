// 3910 : count connected subgraphs with even node sum
// You are given an undirected graph with n nodes labeled from 0 to n - 1. Node i has a value of nums[i], which is either 0 or 1. The edges of the graph are given by a 2D array edges where edges[i] = [ui, vi] represents an edge between node ui and node vi.

// For a non-empty subset s of nodes in the graph, we consider the induced subgraph of s generated as follows:

// We keep only the nodes in s.
// We keep only the edges whose two endpoints are both in s.
// Return an integer representing the number of non-empty subsets s of nodes in the graph such that:

// The induced subgraph of s is connected.
// The sum of node values in s is even.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int f = n;

        vector<vector<int>> adj(n);
        for ( auto& e : edges ){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int count = 0;
        for (int m = 1; m<(1<<n); m++){
            vector<int> node;
            int sum=0;
            for(int i=0; i<n; i++){
                if((m>>i)&1){
                    node.push_back(i);
                    sum += nums[i];
                }
            }
            if (sum%2==0){
                if (isconn(node, adj, m)){
                    count++;
                }
            }
        }
        return count;
    }
private: 
    bool isconn(const vector<int>& node, const vector<vector<int>>& adj, int m){
        if (node.empty()) return false;
        int startnode = node[0];
        queue<int> q;
        q.push(startnode);

        int visitm =(1<< startnode);
        int reachcount = 0;

        while (!q.empty()){
            int u = q.front();
            q.pop();
            reachcount++;

            for (int v : adj[u]){
                if (((m >> v) & 1) && !((visitm >> v) & 1)){
                    visitm |= (1 << v);
                    q.push(v);
                }
            }
        }
        return reachcount == node.size();
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,0,1};
    vector<vector<int>> edges = {{0,1}, {1,2}};  

    int result = sol.evenSumSubgraphs(nums, edges);

    cout << "Total Connected Subgraphs with Even Sum: " << result << endl;

    return 0;
}
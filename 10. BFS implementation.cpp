#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
      vector<int> ans;  // output vector
      queue<int> q;    
      vector<int> vis(V,0);  // take visited array intialy with 0 value
      q.push(0); // push 0 as we start from 0 node of graph
      vis[0]=1;  // mark it as visisted
      while(!q.empty()){ // traverse queue until its empty
        int temp=q.front(); // take front of queue in temp variable
        q.pop();   //pop front of queue
        ans.push_back(temp); // push front of queue in answer vector
        for(auto x: adj[temp])  // traverse all adjacent nodes of queue 
        {
         if(!vis[x]){  // if adjcent nodes are not visisted mark them as 1 and push in queue
          q.push(x);
          vis[x]=1;
         }
        }
      }
      return ans;  // return answer time complexity is O(v+e) as input is given in adjacency list
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

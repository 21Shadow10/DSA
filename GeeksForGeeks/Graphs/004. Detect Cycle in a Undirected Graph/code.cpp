// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool solve(int i, vector<int> &v, vector<int> adj[], int parent) {
        
        v[i] = 1;
        
        for(auto k:adj[i]) {
            if(!v[k]) {
                if(solve(k,v,adj,i))
                    return true ;
            }
            
            else if(k!=parent)
                return true;
        }
        
        return false ;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> v(V,0);
        
        for(int i=0;i<V;i++) {
            if(!v[i]){
                if(solve(i,v,adj,-1))
                    return true ;
            }
        }
        
        return false ;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
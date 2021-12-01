// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  
    bool solve(int i, vector<int> &v, vector<int> &rec, vector<int>adj[]) {
        if(v[i]==0)
        {
            v[i]=1;
            rec[i]=1;
            
            for(auto k:adj[i]) {
                if(!v[k] && solve(k,v,rec,adj))
                    return true ;
                
                else if(rec[k])
                    return true ;
            }
            
            rec[i]=0;
            return false ;
        }
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int> v(V,0),rec(V,0);
        
        for(int i=0;i<V;i++) {a
            if(solve(i,v,rec,adj))
                return true ;
        }
        
        return false ;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
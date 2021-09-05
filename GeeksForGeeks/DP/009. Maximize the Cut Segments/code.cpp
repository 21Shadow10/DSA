// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int N, int x, int y, int z)
    {
        //Your code here
        vector<int>v;
        v.push_back(x) ; 
        v.push_back(y) ;
        v.push_back(z) ;
        
        int dp[4][N+1] ;
        
        for(int i=0;i<=3;i++)
        {
            for(int j=0;j<=N;j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                    
                else if(v[i-1]<=j)
                {
                    if(v[i-1]!=j && dp[i][j-v[i-1]]==0)
                        dp[i][j] = dp[i-1][j] ;
                    
                    else
                        dp[i][j] = max(dp[i-1][j], 1 + dp[i][j-v[i-1]]) ;
                }
                    
                else
                    dp[i][j] = dp[i-1][j] ;
            }
        }
        
        return dp[3][N] ;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
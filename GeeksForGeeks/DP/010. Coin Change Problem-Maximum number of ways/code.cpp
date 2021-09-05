// { Driver Code Starts
#include<iostream>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       
        //code here.
        long long dp[m+1][n+1] ;
        
        for(int i=0;i<=m;i++)
            dp[i][0] = 1;
            
        for(int i=0;i<=n;i++)
            dp[0][i] = 0 ;
            
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(S[i-1]<=j)
                    dp[i][j] = dp[i][j-S[i-1]] + dp[i-1][j] ;
                    
                else
                    dp[i][j] = dp[i-1][j] ;
                    
                //cout<<dp[i][j]<<" " ;
            }
            //cout<<endl ;
        }
        
        return dp[m][n] ;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int N)  { 
	    // Your code goes here
	    int Range = 0;
	    int i,j;
	    
	    for(i=0;i<N;i++)
	        Range += arr[i] ;
	        
	    bool dp[N+1][Range+1] ;
	    
	    for(i=0;i<=N;i++)
	        dp[i][0] = true ;
	        
	    for(i=1;i<=Range;i++)
	        dp[0][i] = false ;
	        
	        
	    for(i=1;i<=N;i++)
	    {
	        for(j=1;j<=Range;j++)
	        {
	            if(arr[i-1]<=j)
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]] ;
	                
	            else
	                dp[i][j] = dp[i-1][j] ;
	        }
	    }
	    
	    int diff = INT_MAX;
  
        for (int j = Range / 2; j >= 0; j--) {
            // Find the
            if (dp[N][j] == true) {
                diff = Range - 2 * j;
                break;
            }
        }
    return diff;
    
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
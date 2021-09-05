#include <iostream>
using namespace std;

int countSubsetSumWithDifference(int arr[], int n, int diff)
{
    int sum = 0;

    for(int i=0;i<n;i++)
        sum += arr[i] ;

    int SubsetSum = (diff+sum)/2 ;

    int dp[n+1][SubsetSum+1] ;
    
    for(int i=0;i<=SubsetSum;i++)
        dp[0][i] = 0;
        
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
        
        
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=SubsetSum;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]] ;
                
            else
                dp[i][j] = dp[i-1][j] ;
                
            //cout<<dp[i][j]<<" " ;
        }
        
        //cout<<endl ;
    }
    
    return dp[n][SubsetSum] ;
        
}

int main() {
	int n;
	cin>>n ;
	
	int arr[n],diff ;
	
	for(int i=0;i<n;i++)
	cin>>arr[i] ;
	
	cin>>diff ;
	
	cout<<countSubsetSumWithDifference(arr,n,diff) ;
	return 0;
}
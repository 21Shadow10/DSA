#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e6;
int a[N],f[N],b[N] ;
 
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 
int32_t main() 
{
    OJ 
    int T ;
    cin>>T;

    while(T--)
    {
        int n;
        cin>>n;

        int sum=0,S=0;
        for(int i=1;i<n+1;i++)
        {
            cin>>a[i] ;
            sum += a[i] ;
            //cout<<sum<<endl ;
        }

        sort(a,a+n+1) ;

        // for(int i=1;i<n+1;i++)
        //    cout<<a[i]<<" " ;
        //    cout<<endl ;

        f[1] = a[1];
        b[n] = a[n] ;

        for(int i=2;i<n+1;i++)
        {
            f[i] = __gcd(f[i-1],a[i]) ;
            //cout<<f[i]<<" ";
        }
        //cout<<endl ;

        for(int i=n-1;i>0;i--)
        {
            b[i] = __gcd(b[i+1],a[i]) ;
            //cout<<b[i]<<" " ;
        }
        //cout<<endl;

        int res = LLONG_MAX ;

        for(int i=1;i<n+1;i++)
        {
            S = (sum-a[i])/__gcd(f[i-1],b[i+1]) + 1 ;

            res = min(res,S) ;
        }

        cout<<res<<endl ;
            

    }
 
 
 
 
return 0;
   
}
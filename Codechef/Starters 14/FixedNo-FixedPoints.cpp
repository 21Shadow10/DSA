#include<bits/stdc++.h>
#include<cmath>
using namespace std;
 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define w(t) ll t;cin>>t;while(t--)
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
int main() 
{
    OJ

    w(t)
    {
        ll n,k;
        cin>>n>>k;

        if((n-k)==1)
            cout<<-1;

        else if(n==k)
            for(int i=1;i<=n;i++)
                cout<<i<<" " ;
            

        else {
            for(int i=1;i<=k;i++)
                cout<<i<<" ";

            for(int i=k+2;i<=n;i++)
                cout<<i<<" ";

            cout<<k+1;
        }

        cout<<endl;
    }
 
 
 
return 0;
   
}
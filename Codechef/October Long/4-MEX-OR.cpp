#include<bits/stdc++.h>
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
    //OJ
    w(t)
    {
        ll x;
        cin>>x;

        if(x==0 || x==1)
            cout<<x+1<<endl;

        else if(floor(log2(x)) == ceil(log2(x))) {
            cout<<x<<endl ;
        }

        else if(floor(log2(x+1)) == ceil(log2(x+1))) {
            cout<<x+1<<endl ;
        }

        else {
            ll ans = 1;
            while(ans<=x)
                ans*=2;

            cout<<ans/2<<endl ;
        }
    }
 
 
 
 
 
return 0;
   
}
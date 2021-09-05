#include<bits/stdc++.h>
using namespace std;
 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define w(t) ll t;cin>>t;while(t--)
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
      int n;
      ll x;
      cin>>n>>x;
      vector<ll>arr(n);
      for(ll i=0;i<n;i++)
      cin>>arr[i];
      map<ll,ll> m1;
      map<ll,ll> m2;
      for(ll i=0;i<n;i++)
      {
        m1[arr[i]]++;
      }
      for(ll i=0;i<n;i++)
      {
        if((arr[i]^x)!=arr[i])
        m2[(arr[i]^x)]++;
        
      }
      ll maximum=0;
      ll minimum=1e18;
      for(ll i=0;i<n;i++)
      {
        if(m1[arr[i]]+m2[arr[i]]>=maximum)
        {
          if(m1[arr[i]]+m2[arr[i]]==maximum&&m2[arr[i]]>minimum)
          continue;
          maximum=m1[arr[i]]+m2[arr[i]];
          minimum=m2[arr[i]];
          ///cout<<maximum<<" "<<array[i]<<endl;
        }

      }
     cout<<maximum<<" "<<minimum<<endl;
    }
}
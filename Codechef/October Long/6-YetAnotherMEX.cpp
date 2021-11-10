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
    OJ
    w(t)
    {
        int n,k ;
        cin>>n>>k;
        vi arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr.begin(),arr.end()) ;

        vi ans ;

        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                int a = 0;

                for(int k=i;k<=j;k++) {
                    if(arr[k]!=a) {
                        ans.push_back(a);
                        break;
                    }
                    
                    a++;
                }
                if(a>j-i)
                    ans.push_back(a);
            }
        }

        sort(ans.begin(),ans.end()) ;

        cout<<ans[k-1]<<endl ;
    }
 
 
 
 
 
return 0;
   
}
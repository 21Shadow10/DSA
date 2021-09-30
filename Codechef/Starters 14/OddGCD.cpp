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
        ll n;
        cin>>n;
        ll arr[n];
        int flag = 0;

        for(ll i=0;i<n;i++) {
            cin>>arr[i] ;
            if(arr[i]%2==1 && flag==0){
                cout<<"0"<<endl;
                flag=1;
            }

        }

        if(flag==0){
            int count = 0;

            while(flag==0) {
                for(ll i=0;i<n;i++) {
                    arr[i] = arr[i]/2;
                    if(arr[i]%2==1){
                        flag=1;
                        break ;
                    }
                }
                count++;
            }

            cout<<count<<endl;
        }

        //cout<<endl; 
        
    }
 
 
 
return 0;
   
}
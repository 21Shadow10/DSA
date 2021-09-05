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

    int T ;
    cin>>T ;

    while(T--)
    {
        int N, k;

        long long a = pow(2,N) ;

        vi arr ;

        for(int i=0;i<a;i++)
        {
            arr.push_back(i) ;
        }
        int left = 0, right=a-1; 

        while(left<right && k>0)
        {
            swap(arr[left],arr[right]) ;
            left++;
            right--;
            k--;
        }

        int ans = 0;

        cout<<"out " ;

        for(int i=0;i<a;i++)
        {
            cout<<"in " ;
            cout<<(i^arr[i])<<" " ;
        }
        cout<<endl ;
        //cout<<ans<<endl ;
    }
return 0;
   
}
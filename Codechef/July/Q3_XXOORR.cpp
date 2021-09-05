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
 
void dectobin(int n, vector<int> &binary)
{
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            binary[i]++ ;
    }
    return ;
}
 
int main() 
{
    OJ
    int T ;
    cin>>T ;
    while(T--)
    {
        int N,K ;
        cin>>N>>K ;

        vector<int> binary(32,0) ;
        int arr[N] ;
        for(int i=0;i<N;i++)
        {
            cin>>arr[i] ;
            dectobin(arr[i],binary) ;
        }

        int result = 0;

        for(int i=0;i<32;i++)
            result += ceil(binary[i]/(float)(K)) ;

        cout<<result<<endl ;
    }
 
 
 
return 0;
   
}
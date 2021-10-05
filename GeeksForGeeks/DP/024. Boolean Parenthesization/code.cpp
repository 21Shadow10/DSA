// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string,int> mp;
    int solve(string st,int i,int j,bool isTrue) {
		if(i>j) return 0;
		if(i==j) {
			if(isTrue) {
				return st[j]=='T';
			}else {
				return st[j]=='F';
			}
		}
		string key = to_string(i);
		key.push_back(' ');
		key.append(to_string(j));
		key.push_back(' ');
		key.append(to_string(isTrue));
        if(mp.find(key) != mp.end()){
            return mp[key];
        }
		int answer=0;
		for(int k=i+1;k<j;k+=2) {
			int lt=solve(st,i,k-1,true);
			int lf=solve(st,i,k-1,false);
			int rt=solve(st,k+1,j,true);
			int rf=solve(st,k+1,j,false);
			
			if(st[k] == '&') {
				if(isTrue) {
					answer+=lt*rt;
				}else {
					answer+=lt*rf+lf*rt+lf*rf;
				}
			}else if(st[k] == '^') {
				if(isTrue) {
					answer+=lt*rf+lf*rt;
				}else {
					answer+=lt*rt+lf*rf;
				}
			}else if(st[k] == '|') {
				if(isTrue) {
					answer+=lt*rt+lt*rf+lf*rt;
				}else {
					answer+=lf*rf;
				}
			}
		}
		mp[key] = answer%1003;
		return answer%1003;
	}
    int countWays(int N, string S){
        return solve(S,0,N-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
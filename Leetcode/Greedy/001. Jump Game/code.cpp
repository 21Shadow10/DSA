class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int n = nums.size() ;
        for(int j=0;i<n&&i<=j;i++) {
            j = max(i+nums[i],j) ;
        }
        
        return i==n;
    }
};
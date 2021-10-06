class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1;
        int maxProdLR = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++)
        {
            prod = prod * nums[i];
            
            maxProdLR = max(maxProdLR, prod);
            
            if(prod == 0)
                prod = 1;
        }
        
        prod = 1;
        int maxProdRL = INT_MIN;
        
        for(int i = nums.size() - 1; i>=0; i--)
        {
            prod = prod * nums[i];
            
            maxProdRL = max(maxProdRL, prod);
            
            if(prod == 0)
                prod = 1;
        }
        
        return max(maxProdRL, maxProdLR);
        
        //return maxProdLR ;
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        int ans  = op(nums, dp,  n-1);
        return ans;
    }

    int op(vector<int>& nums,vector<int>& dp, int idx){
        if(idx == 0){
            return nums[0];
        }
        if(idx==1){
            return max(nums[idx], nums[0]);
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        dp[idx] = max(op(nums,dp, idx-1),op(nums,dp, idx-2)+nums[idx]);
        return dp[idx];
    }
};
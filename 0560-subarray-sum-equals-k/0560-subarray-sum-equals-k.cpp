class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;

        for(int l = 0; l<n; l++){
            for(int r = l; r<n; r++){
                sum += nums[r];
                if(sum == k) ans++;
            }
            sum = 0;
        }
       return ans;
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int rob = 0;
        int norob = 0;
        for (int i = 0; i<nums.size()-1; i++) {
            int newRob = norob + nums[i];
            int newNoRob = max(norob, rob);
            rob = newRob;
            norob = newNoRob;
        }

        int ans1 = max(rob, norob);
        rob = 0;
        norob=0;
        for (int i = 1; i<nums.size(); i++) {
            int newRob = norob + nums[i];
            int newNoRob = max(norob, rob);
            rob = newRob;
            norob = newNoRob;
        }
        int ans2 = max(rob,norob);

        return max(ans1,ans2);
    }

};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        op(nums, curr, ans, 0);
        return ans;
    }

    void op(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int start) {
        ans.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            op(nums, curr, ans, i+1);
            curr.pop_back();
        }
    }
};
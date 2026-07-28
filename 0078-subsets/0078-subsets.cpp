class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        op(nums,ans,0,curr);
        return ans;
    }

    void op(vector<int>& nums, vector<vector<int>>& ans, int pos, vector<int>& curr) {
        if(pos==nums.size()){
            ans.push_back(curr);
            return;
        }

        op(nums,ans,pos+1,curr);
        curr.push_back(nums[pos]);
        op(nums,ans,pos+1,curr);

        curr.pop_back();
    }
};
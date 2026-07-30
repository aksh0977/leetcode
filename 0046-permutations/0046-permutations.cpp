class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n,0);
        vector<int> curr;
        vector<vector<int>> ans;
        op(vis,nums,curr,ans);
        return ans;
    }
     void op(vector<bool>& vis, vector<int>& nums,
                vector<int>& curr,vector<vector<int>>& ans){
            int n = nums.size();
            if(curr.size()==n){
                ans.push_back(curr);
                return;
            }

            for(int i=0; i<n; i++){
                if(!vis[i]){
                    vis[i]=true;
                    curr.push_back(nums[i]);
                    op(vis,nums,curr,ans);
                    vis[i]=false;
                    curr.pop_back();
                }
            }
    }
};
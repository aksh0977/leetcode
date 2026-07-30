class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        vector<int> curr;
        vector<vector<int>> ans;
        int start=0;
        op(ans, candidates, curr,  sum, target, start);
        return ans;
    }
    void op(vector<vector<int>>& ans, vector<int>& arr, vector<int>& curr, int& sum,int target,int start){
        if(sum==target){
            ans.push_back(curr);
            return;
        }    
        for(int i=start; i<arr.size(); i++){
            if(sum+arr[i]<=target){
                sum+=arr[i];
                curr.push_back(arr[i]);
                op(ans, arr, curr, sum, target,i);

                sum-=arr[i];
                curr.pop_back();
            }
        }
    }
};
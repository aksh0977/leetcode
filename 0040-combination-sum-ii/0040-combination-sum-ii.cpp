class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum = 0;
        vector<int> curr;
        vector<vector<int>> ans;
        int start=0;
        sort(candidates.begin(), candidates.end());
        op(ans, candidates, curr,  sum, target, start);
        return ans;
    }
    void op(vector<vector<int>>& ans, vector<int>& arr, vector<int>& curr, int& sum,int target,int start){
        if(sum==target){
            ans.push_back(curr);
            return;
        }    
        for(int i=start; i<arr.size(); i++){
            if (i > start && arr[i] == arr[i-1]) continue;
            if(sum+arr[i]<=target){
                sum+=arr[i];
                curr.push_back(arr[i]);
                op(ans, arr, curr, sum, target,i+1);

                sum-=arr[i];
                curr.pop_back();
            }
        }
    }
};
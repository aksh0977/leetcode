class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(score(i,nums,n)<=k){
                return i;
            }
        }
        return -1;
    }
    int score(int i, vector<int>& nums, int n){
        return maxi(i,nums,n) - mini(i,nums,n);

    }
    int maxi(int i, vector<int>& nums, int n){
        int op = -1e9;
        for(int j = 0; j<i+1 && i<n; j++){
            op = max(op,nums[j]);
        }
        return op;
    }
    int mini(int i, vector<int>& nums, int n){
        int op = 1e9;
        for(int j = i; j<n; j++){
            op = min(op,nums[j]);
        }
        return op;
    }
};
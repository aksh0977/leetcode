class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        if(nums1[0]%2==1) return true;
        else{
            for(int n : nums1){
                if(n%2==1){
                    return false;
                }
            }
            return true;
        }
    }
};
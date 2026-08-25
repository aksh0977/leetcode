class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      int op = 1;
      int i =0 ;
      while(i<nums.size()){
        if(nums[i]<k*op){
            i++;
        }
        else if(nums[i]==k*op){
            i++;
            op++;
        }
        else{
            break;
        }
      }
      return k*op;
    }
};
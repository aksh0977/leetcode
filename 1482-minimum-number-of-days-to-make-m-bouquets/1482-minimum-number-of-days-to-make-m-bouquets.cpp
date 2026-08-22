class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long)m*k>bloomDay.size()) return -1;
        int left = 1;
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while(left<=right){
            int mid = left + (right-left)/2;
            if(op(bloomDay,  m, k, mid)){
                right = mid-1;
            }
            else left= mid+1;
        }
        return left;
        
    }
    bool op(vector<int>& bloomDay, int m, int k, int d){
        int count=0;
        int ans=0;
        for(int i=0;  i<bloomDay.size(); i++){
            if(bloomDay[i]<=d){
                count++;
            }
            else{
                ans+=count/k;
                count=0;
            }
        }
        ans+=count/k; 
           if(ans>=m){
        return true;
    }
    else return false;
    }

};
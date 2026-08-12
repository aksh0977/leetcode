class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int i =0;
        while(i<n){
            int j = i;
            while(j<n-1 && intervals[j+1][0]<=intervals[j][1]){
                intervals[j+1][1] = max(intervals[j+1][1], intervals[j][1]);
                j++;
            }
            ans.push_back({intervals[i][0],intervals[j][1]});
            i = j+1;
        }
        return ans;
    }
};
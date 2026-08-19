class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {
        sort(seats.begin(),seats.end());
        int s = seats.size();
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<s;i++){
            mp[seats[i][0]].push_back(seats[i][1]);
        }
        int ans = (n - mp.size()) * 2;
        for (auto op : mp) {
            bool left = true;   
            bool middle = true; 
            bool right = true;  
            for (int seat : op.second) {
                if (seat >= 2 && seat <= 5)
                    left = false;

                if (seat >= 4 && seat <= 7)
                    middle = false;

                if (seat >= 6 && seat <= 9)
                    right = false;
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};
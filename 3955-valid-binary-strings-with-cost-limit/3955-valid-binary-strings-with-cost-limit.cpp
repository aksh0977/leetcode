class Solution {
public:
        void op(int idx,vector<string>& ans, string &curr, int sum, int n, int k){
        if(idx==n){
            ans.push_back(curr);
            return;
        }

        curr.push_back('0');
        op(idx+1,ans,curr,sum,n,k);
        curr.pop_back();

        if(( curr.empty() ||curr.back()!='1' )&& sum+idx<=k){
            curr.push_back('1');
            op(idx+1, ans,curr,sum+idx,n,k);
            curr.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        string curr = "";
        int sum = 0;
        op(0, ans,curr,sum,n,k);
        return ans;
    }


};
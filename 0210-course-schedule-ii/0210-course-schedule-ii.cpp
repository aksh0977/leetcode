class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(N);

        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        vector<int> indg(N, 0);
        vector<int> ans;
        for(int i=0; i<N; i++){
            for(auto it : adj[i]){
                indg[it]++;
            }
        }
        queue<int> q;
        
        for(int i=0; i<N; i++){
            if(indg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            for(auto it : adj[node]){
                indg[it]--;
                if(indg[it]==0){
                q.push(it);
                }   
            }
            q.pop();       
        }
        vector<int> op;
        return ans.size()<N ? op : ans;
    }
};
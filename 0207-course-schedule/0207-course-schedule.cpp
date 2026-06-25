class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(N);

        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        vector<int> indg(N, 0);
       int   cnt =0 ;
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
            cnt++;
            for(auto it : adj[node]){
                indg[it]--;
                if(indg[it]==0){
                q.push(it);
                }   
            }
            q.pop();       
        }
        return cnt<N ? false : true;
    }
};
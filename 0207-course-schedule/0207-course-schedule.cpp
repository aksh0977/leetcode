class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(N);

        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(N, 0);
        vector<int> path(N, 0);
        for(int i=0; i<N; i++){
            if(vis[i]==0){
                if(cycleExists(adj, vis, path, i)) return false;
            }
        }
        return true;
    }
    bool cycleExists(vector<vector<int>>& adj,  vector<int>& vis, vector<int>& path,  int i){
        vis[i] = 1;
        path[i] = 1;

        for (auto it : adj[i]) {
            if (!vis[it]) {
                if (cycleExists(adj, vis, path, it))
                    return true;
            }
            else if (path[it]) {
                return true;
            }
        }
        path[i] = 0;
        return false;
    }
};
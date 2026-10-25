class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(isWater[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int r=curr.first.first;
            int c = curr.first.second;
            int height = curr.second;

            ans[r][c] = height;

            for(int i = 0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr<m && nr>=0
                    && nc<n && nc>=0
                    && !vis[nr][nc]
                ){
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},height+1});

                }
            }

        }
        return ans;
    }
};
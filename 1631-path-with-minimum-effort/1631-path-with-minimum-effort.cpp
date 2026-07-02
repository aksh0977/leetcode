class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!pq.empty()){

            auto [d,node] = pq.top();
            pq.pop();

            int r = node.first;
            int c = node.second;

            if(r==n-1 && c==m-1)
                return d;
            if(d > dist[r][c])
                continue;
            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr<0 || nr>=n || nc<0 || nc>=m)
                    continue;

                int newEffort = max(
                    d,
                    abs(heights[r][c]-heights[nr][nc])
                );

                if(newEffort < dist[nr][nc]){
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort,{nr,nc}});
                }
            }
        }
        return 0;
    }
};
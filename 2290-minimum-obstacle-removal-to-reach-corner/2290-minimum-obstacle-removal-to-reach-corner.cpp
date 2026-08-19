class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dist(m, vector<int>(n, 1e9));
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        while(!pq.empty()){
            int step = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop(); 
            for(int i = 0; i < 4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                    if(step + grid[nr][nc] < dist[nr][nc]){
                        dist[nr][nc] = step + grid[nr][nc];
                        pq.push({step + grid[nr][nc],{nr, nc}});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];

    }
};
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>>pq;
        pq.push({0, 0, 0, 0});
        vector<vector<int>>dist(m, vector<int>(n, 1e9));
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        dist[0][0] = grid[0][0];
        while(!pq.empty()){
            auto[rem , cost , r, c] = pq.top();
            pq.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                    if(grid[nr][nc] + rem <= k && dist[nr][nc] > cost + 1){
                        dist[nr][nc] = cost + 1;
                        pq.push({grid[nr][nc] + rem, cost + 1, nr, nc});
                    }
                }
            }
        }
        return dist[m - 1][n - 1] == 1e9 ? -1 : dist[m - 1][n - 1];
    }
};
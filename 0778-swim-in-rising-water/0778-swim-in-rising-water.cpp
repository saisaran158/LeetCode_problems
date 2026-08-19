class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       vector<vector<int>>dist(m, vector<int>(n, 1e9));
       dist[0][0] = 0;
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
       pq.push({grid[0][0],{0, 0}});
       int delr[] = {-1, 0, 1, 0};
       int delc[] = {0, 1, 0, -1};
       while(!pq.empty()){
        int time = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        for(int i = 0; i < 4; i++){
            int nr = row + delr[i];
            int nc = col + delc[i];

            if(nr < m && nr >= 0 && nc >=0 && nc < n){
                int maxy = max(time, grid[nr][nc]);
                if(dist[nr][nc] > maxy){
                    dist[nr][nc] = maxy;
                    pq.push({maxy,{nr, nc}});
                }
            }
        }
       }
       return dist[m - 1][n - 1];
    }
};
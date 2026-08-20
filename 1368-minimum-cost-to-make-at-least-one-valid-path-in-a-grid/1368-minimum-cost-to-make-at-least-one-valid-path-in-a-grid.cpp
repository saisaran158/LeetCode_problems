class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, INT_MAX));
        vis[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({0, {0, 0}});
        int delr[] = {0, 0, 1, -1};
        int delc[] = {1, -1, 0, 0};
        string dir = "1234";
        while(!pq.empty()){
            int cost = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                    int newCost = cost;
                    if(grid[r][c] != dir[i] - '0'){
                        newCost++;
                    }
                    if(newCost < vis[nr][nc]){
                        vis[nr][nc] = newCost;
                        pq.push({newCost,{nr, nc}});
                    }
                }
            }
        }
        return vis[m - 1][n - 1];
    }
};
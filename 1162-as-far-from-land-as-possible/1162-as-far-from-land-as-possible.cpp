class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        if(q.size() == m * n) return -1;
        int ans = -1;
        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nr = r + delr[i];
                    int nc = c + delc[i];
                    if(nr >= 0 && nc >= 0 && nr < m && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 0){
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};
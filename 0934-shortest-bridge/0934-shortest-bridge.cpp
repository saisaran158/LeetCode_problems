class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    break;
                }
            }
            if(!q.empty()) break;
        }
        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + delr[i];
                int nc = c + delc[i];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                    grid[nr][nc] == 1 && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j])
                    q.push({i, j});
            }
        }
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + delr[i];
                    int nc = c + delc[i];
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                        !vis[nr][nc]) {
                        if(grid[nr][nc] == 1){
                            return ans;
                        }
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
class Solution {
public:
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, 1, 0, -1};
    void bfs(vector<vector<int>>& grid, int i, int j, int& curr,
             vector<vector<int>>& vis, int& m, int& n) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        curr += grid[i][j];
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + delr[k];
                int nc = c + delc[k];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                    grid[nr][nc] != 0 && vis[nr][nc] == 0) {
                    vis[nr][nc] = 1;
                    curr += grid[nr][nc];
                    q.push({nr, nc});
                }
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0;
        int curr;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    curr = 0;
                    bfs(grid, i, j, curr, vis, m, n);
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};
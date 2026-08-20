class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int count = 1;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        while (!q.empty()) {
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            int rows[] = {-1, 0, 1, 0};
            int cols[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nr = nrow + rows[i];
                int nc = ncol + cols[i];
                if (nr < n && nc < m && nc >= 0 && nr >= 0 &&
                    grid[nr][nc] == 1 && vis[nr][nc] == 0) {
                    vis[nr][nc] = 1;
                    count++;
                    q.push({nr, nc});
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int c = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    c = max(c, bfs(i, j, vis, grid));
                }
            }
        }
        return c;
    }
};
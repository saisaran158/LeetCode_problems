class Solution {
public:
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, 1, 0, -1};
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& vis, int m, int n){
        vis[r][c] = 1;

        for(int i = 0; i < 4; i++){
            int nr = r + delr[i];
            int nc = c + delc[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 0){
                dfs(grid, nr, nc, vis, m, n);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0)
            dfs(grid, i, 0, vis, m, n);
            if(grid[i][n - 1] == 0)
            dfs(grid, i, n - 1, vis, m, n);
        }
        for(int j = 0; j < n; j++){
            if(grid[0][j] == 0)
            dfs(grid, 0, j, vis, m, n);
            if(grid[m - 1][j] == 0)
            dfs(grid, m - 1, j, vis, m, n);
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0 && vis[i][j] == 0){
                    ans++;
                    dfs(grid, i, j, vis, m, n);
                }
            }
        }
        return ans;
    }
};
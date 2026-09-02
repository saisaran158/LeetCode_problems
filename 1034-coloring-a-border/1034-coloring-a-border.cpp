class Solution {
public:
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, 1, 0, -1};
    void dfs(int row, int col, vector<vector<int>>& grid, int& color, int& m, int& n, int& curr, vector<vector<int>>& vis){
        if(row == 0 || row == m - 1 || col == 0 || col == n - 1){
            grid[row][col] = color;
        }
        vis[row][col] = 1;
        for(int i = 0; i < 4; i++){
            int nr = row + delr[i];
            int nc = col + delc[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0){
                if(grid[nr][nc] == curr){
                    dfs(nr, nc, grid, color, m ,n, curr, vis);
                }
                else{
                    grid[row][col] = color;
                }
            }
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        int curr = grid[row][col];
        dfs(row, col, grid, color, m, n, curr, vis);
        return grid;
    }
};
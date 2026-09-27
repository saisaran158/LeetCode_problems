class Solution {
public:
    int m, n;
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, 1, 0, -1};
    bool dfs(int r, int c, vector<vector<int>>&grid1, vector<vector<int>>&grid2, vector<vector<int>>& vis){
        vis[r][c] = 1;
        bool ans = grid1[r][c] == 1;
        for(int i = 0; i < 4; i++){
            int nr = r + delr[i];
            int nc = c + delc[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && !vis[nr][nc]){
                if(grid2[nr][nc] == 1){
                    ans = dfs(nr, nc, grid1, grid2, vis) && ans;
                }
            }
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        m = grid1.size();
        n = grid1[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1 && !vis[i][j]){
                    if(dfs(i, j, grid1, grid2, vis)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
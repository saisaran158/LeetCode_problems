class Solution {
public:
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<int>>& land, vector<vector<int>>& vis, int& e1, int& e2){
        if (r >= e1) e1 = r;
        if (c >= e2) e2 = c;
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++){
            int nr = r + delr[i];
            int nc = c + delc[i];

            if (nr >= 0 && nc >= 0 && nr < land.size() && nc < land[0].size() && land[nr][nc] == 1 && vis[nr][nc] == 0){
                dfs(nr, nc, land, vis, e1, e2);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>res;
        int m = land.size();
        int n = land[0].size();
        int e1 = 0, e2 = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (land[i][j] == 1 && vis[i][j] == 0){
                    e1 = 0;
                    e2 = 0;
                    dfs(i, j, land, vis, e1, e2);
                    res.push_back({i, j, e1, e2});
                }
            }
        }
        return res;
    }
};
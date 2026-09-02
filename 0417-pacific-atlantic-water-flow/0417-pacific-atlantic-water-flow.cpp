class Solution {
public: 
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<int>>& pacific){
        pacific[r][c] = 1;
        int m = heights.size();
        int n = heights[0].size();
        for(int i = 0; i < 4; i++){
            int nr = r + delr[i];
            int nc = c + delc[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && heights[nr][nc] >= heights[r][c] && pacific[nr][nc] == 0){
                dfs(nr, nc, heights, pacific);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>pacific(m, vector<int>(n, 0));
        vector<vector<int>>atlantic(m, vector<int>(n, 0));
        vector<vector<int>>res;
        for(int i = 0; i < n; i++){
            dfs(0, i, heights, pacific);
        }
        for(int i = 0; i < m; i++){
            dfs(i, 0, heights, pacific);
        }
        for(int i = 0; i < m; i++){
            dfs(i, n - 1, heights, atlantic);
        }
        for(int i = 0; i < n; i++){
            dfs(m - 1, i, heights, atlantic);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] == 1 && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
        
    }
};
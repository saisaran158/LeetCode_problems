class Solution {
public:
    int m, n;
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, 1, 0, -1};
    bool bfs(int r, int c, vector<vector<int>>&grid1, vector<vector<int>>&grid2, vector<vector<int>>& vis){
        vis[r][c] = 1;
        queue<pair<int, int>>q;
        q.push({r, c});
        bool ans = true;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nr = row + delr[i];
                int nc = col + delc[i];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid2[nr][nc] == 1 && !vis[nr][nc]){
                    if(grid1[nr][nc] == 0){
                        ans = false;
                    }

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
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
                if(grid2[i][j] == 1 && !vis[i][j] && grid1[i][j] == 1){
                    if(bfs(i, j, grid1, grid2, vis)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
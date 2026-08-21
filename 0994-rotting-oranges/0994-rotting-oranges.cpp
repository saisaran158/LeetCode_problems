class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int vis[m][n];
        queue<pair<pair<int, int>, int>>q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int ans = -0;
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            ans = max(ans, t);

            for(int i = 0; i < 4; i++){
                int nr = row + delr[i];
                int nc = col + delc[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                    if(vis[nr][nc] == 0 && grid[nr][nc] == 1){
                        vis[nr][nc] = 2;
                        q.push({{nr, nc}, t + 1});
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2){
                    return -1;
                }
            }
        }
        return ans;

    }
};
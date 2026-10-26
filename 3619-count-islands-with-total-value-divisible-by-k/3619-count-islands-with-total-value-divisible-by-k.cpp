class Solution {
public:
    long long bfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& vis){
        long long sum = 0;
        vis[r][c] = 1;
        sum = grid[r][c];
        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, 1, 0, -1};
        queue<pair<int, int>>q;
        q.push({r, c});
        while(!q.empty()){
            int nr = q.front().first;
            int nc = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int dr = nr + delr[i];
                int dc = nc + delc[i];
                if(dr >= 0 && dc >= 0 && dr < grid.size() && dc < grid[0].size() && vis[dr][dc] == 0 && grid[dr][dc] != 0){
                    vis[dr][dc] = 1;
                    sum += grid[dr][dc];
                    q.push({dr, dc});
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    if(bfs(grid, i, j, vis) % k == 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
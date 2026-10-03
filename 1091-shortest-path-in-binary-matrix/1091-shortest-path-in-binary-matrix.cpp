class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        if(grid[n - 1][n - 1] == 1) return -1;
        queue<tuple<int, int, int>>q;
        q.push({0, 0, 1});
        vector<vector<int>>vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        while(!q.empty()){
            auto[r, c, step] = q.front();
            if(r == n - 1 && c == n - 1) return step;
            q.pop();

            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int nr = r + i;
                    int nc = c + j;
                    if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0 && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr, nc, step + 1});
                    }
                }
            }
        }
        return -1;
    }
};
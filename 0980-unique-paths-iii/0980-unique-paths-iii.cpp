class Solution {
public:
    void recursion(int sr, int sc, int er, int ec, vector<vector<int>>& grid, int count, int& ans, vector<vector<int>>& vis){
        if(sr == er && sc == ec){
            cout << sr << "-" << sc << "-" << count << " ";
            if(count == 0){
                ans++;
            }
            return;
        }
        vis[sr][sc] = 1;
        int m = grid.size();
        int n = grid[0].size();
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nr = sr + delr[i];
            int nc = sc + delc[i];

            if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                if(grid[nr][nc] != -1 && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    count--;
                    recursion(nr, nc, er, ec, grid, count, ans, vis);
                    count++;
                    vis[nr][nc] = 0;
                }
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        int count = grid.size() * grid[0].size();
        int sr,sc,er,ec, c = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    sr = i;
                    sc = j;
                }
                if(grid[i][j] == 2){
                    er = i; 
                    ec = j;
                }
                if(grid[i][j] == -1){
                    c++;
                }
            }
        }
        vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(), 0));
        recursion(sr, sc, er, ec, grid, count - 1 - c, ans, vis);
        return ans;
    }
};
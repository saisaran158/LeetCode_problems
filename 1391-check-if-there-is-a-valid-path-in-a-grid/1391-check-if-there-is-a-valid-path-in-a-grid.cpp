class Solution {
public:
    int m, n;
    bool check(int i, int j){
        if(i >= 0 && j >= 0 && i < m && j < n) return true;
        return false;
    }
    bool dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        if(r == m - 1 && c == n - 1) return true;
        vis[r][c] = 1;
        if(grid[r][c] == 1){
            int nr = r;
            int nc = c - 1;
            if(check(nr, nc) && !vis[nr][nc]){
                if(grid[nr][nc] == 4 || grid[nr][nc] == 6 || grid[nr][nc] == 1){
                    if(dfs(nr, nc, grid, vis)) return true;
                }
            }
            int nrx = r;
            int ncx = c + 1;
            if(check(nrx, ncx) && !vis[nrx][ncx]){
                if(grid[nrx][ncx] == 3 || grid[nrx][ncx] == 5 || grid[nrx][ncx] == 1){
                    if(dfs(nrx, ncx, grid, vis)) return true;
                }
            }
        }
        else if(grid[r][c] == 2){
            int nr = r - 1;
            int nc = c;
            if(check(nr, nc) && !vis[nr][nc]){
                if(grid[nr][nc] == 4 || grid[nr][nc] == 3 || grid[nr][nc] == 2){
                    if(dfs(nr, nc, grid, vis)) return true;
                }
            }
            int nrx = r + 1;
            int ncx = c;
            if(check(nrx, ncx) && !vis[nrx][ncx]){
                if(grid[nrx][ncx] == 6 || grid[nrx][ncx] == 5 || grid[nrx][ncx] == 2){
                    if(dfs(nrx, ncx, grid, vis)) return true;
                }
            }
        }
        else if(grid[r][c] == 3){
            int nr = r;
            int nc = c - 1;
            if(check(nr, nc) && !vis[nr][nc]){
                if(grid[nr][nc] == 1 || grid[nr][nc] == 4 || grid[nr][nc] == 6){
                    if(dfs(nr, nc, grid, vis)) return true;
                }
            }
            int nrx = r + 1;
            int ncx = c;
            if(check(nrx, ncx) && !vis[nrx][ncx]){
                if(grid[nrx][ncx] == 2 || grid[nrx][ncx] == 5 || grid[nrx][ncx] == 6){
                   if(dfs(nrx, ncx, grid, vis)) return true;
                }
            }
        }
        else if(grid[r][c] == 4){
            int nr = r;
            int nc = c + 1;
            if(check(nr, nc) && !vis[nr][nc]){
                if(grid[nr][nc] == 1 || grid[nr][nc] == 3 || grid[nr][nc] == 5){
                    if(dfs(nr, nc, grid, vis)) return true;
                }
            }
            int nrx = r + 1;
            int ncx = c;
            if(check(nrx, ncx) && !vis[nrx][ncx]){
                if(grid[nrx][ncx] == 2 || grid[nrx][ncx] == 5 || grid[nrx][ncx] == 6){
                    if(dfs(nrx, ncx, grid, vis)) return true;
                }
            }
        }
        else if(grid[r][c] == 5){
            int nr = r;
            int nc = c - 1;
            if(check(nr, nc) && !vis[nr][nc]){
                if(grid[nr][nc] == 1 || grid[nr][nc] == 4 || grid[nr][nc] == 6){
                    if(dfs(nr, nc, grid, vis)) return true;
                }
            }
            int nrx = r - 1;
            int ncx = c;
            if(check(nrx, ncx) && !vis[nrx][ncx]){
                if(grid[nrx][ncx] == 3 || grid[nrx][ncx] == 4 || grid[nrx][ncx] == 2){
                    if(dfs(nrx, ncx, grid, vis)) return true;
                }
            }
        }
        else if(grid[r][c] == 6){
            int nr = r;
            int nc = c + 1;
            if(check(nr, nc) && !vis[nr][nc]){
                if(grid[nr][nc] == 5 || grid[nr][nc] == 3 || grid[nr][nc] == 1){
                    if(dfs(nr, nc, grid, vis)) return true;
                }
            }
            int nrx = r - 1;
            int ncx = c;
            if(check(nrx, ncx) && !vis[nrx][ncx]){
                if(grid[nrx][ncx] == 2 || grid[nrx][ncx] == 3 || grid[nrx][ncx] == 4){
                    if(dfs(nrx, ncx, grid, vis)) return true;
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        return dfs(0, 0, grid, vis);
    }
};
class Solution {
public:
    int m, n;
    bool check(int i, int j){
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int vis[m][n];
        memset(vis, 0, sizeof(vis));
        vis[0][0] = 1;
        queue<pair<int, int>>q;
        q.push({0, 0});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(grid[r][c] == 'R'){
                if(check(r, c + 1) && !vis[r][c + 1]){
                    vis[r][c + 1] = 1;
                    q.push({r, c + 1});
                }
                else{
                    return {r, c};
                }
            }

            else if(grid[r][c] == 'L'){
                if(check(r, c - 1) && !vis[r][c - 1]){
                    vis[r][c - 1] = 1;
                    q.push({r, c - 1});
                }
                else{
                    return {r, c};
                }
            }

            else if(grid[r][c] == 'U'){
                if(check(r - 1, c) && !vis[r - 1][c]){
                    vis[r - 1][c] = 1;
                    q.push({r - 1, c});
                }
                else{
                    return {r, c};
                }
            }

            else if(grid[r][c] == 'D'){
                if(check(r + 1, c) && !vis[r + 1][c]){
                    vis[r + 1][c] = 1;
                    q.push({r + 1, c});
                }
                else{
                    return {r, c};
                }
            }
        }
        return {-1, -1};
    }
};
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<tuple<int, int, int>>q;
        q.push({entrance[0], entrance[1], 0});
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        vis[entrance[0]][entrance[1]] = 1;
        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, 1, 0, -1};
        while(!q.empty()){
            auto[r, c, steps] = q.front();
            q.pop();
            if(r == 0 || r == m - 1 || c == 0 || c == n -1){
                if(r != entrance[0] || c != entrance[1]){
                    return steps;
                }
            }

            for(int i = 0; i < 4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && maze[nr][nc] == '.' && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr, nc, steps + 1});
                }
            }
        }
        return -1;
    }
};
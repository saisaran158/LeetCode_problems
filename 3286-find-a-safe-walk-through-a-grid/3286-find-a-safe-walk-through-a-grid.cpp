class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<tuple<int, int, int, int>,
                       vector<tuple<int, int, int, int>>,
                       greater<tuple<int, int, int, int>>>
            pq;
        pq.push({grid[0][0]+1, 0, 0, 0});
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        dist[0][0] = 0;
        while (!pq.empty()) {
            auto [hp, step, r, c] = pq.top();
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + delr[i];
                int nc = c + delc[i];

                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    if (grid[nr][nc] + hp <= health &&
                        dist[nr][nc] > step + 1) {
                        dist[nr][nc] = step + 1;
                        pq.push({grid[nr][nc] + hp, step + 1, nr, nc});
                    }
                }
            }
        }
        return dist[m - 1][n - 1] != 1e9 ? true : false;
    }
};
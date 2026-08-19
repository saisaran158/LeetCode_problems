class Solution {
public:
    bool bfs(vector<vector<int>>& dungeon, int mid) {
        if (dungeon[0][0] + mid < 1)
            return false;
        queue<pair<int, pair<int, int>>> q;
        q.push({mid + dungeon[0][0], {0, 0}});
        int m = dungeon.size();
        int n = dungeon[0].size();
        int delr[] = {1, 0};
        int delc[] = {0, 1};
        vector<vector<int>> vis(m, vector<int>(n, -1));
        while (!q.empty()) {
            int hp = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            if (r == m - 1 && c == n - 1)
                return true;
            if (vis[r][c] > hp)
                continue;

            for (int i = 0; i < 2; i++) {
                int nr = r + delr[i];
                int nc = c + delc[i];

                if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                    if (hp + dungeon[nr][nc] >= 1 &&
                        vis[nr][nc] < hp + dungeon[nr][nc]) {
                        q.push({hp + dungeon[nr][nc], {nr, nc}});
                        vis[nr][nc] = dungeon[nr][nc] + hp;
                    }
                }
            }
        }
        return false;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int low = 1;
        int high = 1e9;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (bfs(dungeon, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
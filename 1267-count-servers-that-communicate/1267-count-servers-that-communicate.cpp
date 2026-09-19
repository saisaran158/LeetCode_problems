class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int c = 0;
                if (grid[i][j] == 1) {
                    for (int k = 0; k < m; k++) {
                        if (grid[k][j] == 1 && k != i) {
                            c++;
                        }
                    }
                    for (int l = 0; l < n; l++) {
                        if (grid[i][l] == 1 && l != j) {
                            c++;
                        }
                    }
                    if(c >= 1) ans++;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int solve2(vector<vector<int>>& fruits, int r, int c, vector<vector<int>>& dp2) {
        if (r >= fruits.size())
            return -1e9;
        if (r < c)
            return -1e9;
        if (r == c)
            return dp2[r][c] = 0;
        if(dp2[r][c] != -1) return dp2[r][c];
        int f = fruits[r][c];

        f += max({solve2(fruits, r - 1, c + 1, dp2), solve2(fruits, r, c + 1, dp2),
                  solve2(fruits, r + 1, c + 1, dp2)});

        return dp2[r][c] = f;
    }
    int solve1(vector<vector<int>>& fruits, int r, int c, vector<vector<int>>& dp1) {
        if (c >= fruits.size())
            return -1e9;
        if (r > c)
            return -1e9;
        if (r == c)
            return dp1[r][c] = 0;
        if(dp1[r][c] != -1) return dp1[r][c];
        int f = fruits[r][c];

        f += max({solve1(fruits, r + 1, c - 1, dp1), solve1(fruits, r + 1, c, dp1),
                  solve1(fruits, r + 1, c + 1, dp1)});

        return dp1[r][c] = f;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int tot = 0;
        for (int i = 0; i < n; i++) {
            tot += fruits[i][i];
        }
        vector<vector<int>>dp1(n, vector<int>(n, -1));
        vector<vector<int>>dp2(n, vector<int>(n, -1));
        tot += solve1(fruits, 0, n - 1, dp1);
        tot += solve2(fruits, n - 1, 0, dp2);
        return tot;
    }
};
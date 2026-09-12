class Solution {
public:
    long long mod = 1e9 + 7;
    int rec(int start, vector<int> moves[], int len, vector<vector<int>>& dp){
        if(len == 1) return 1;
        if(dp[start][len] != -1) return dp[start][len];
        int tot = 0;
        for(auto next : moves[start]){
            tot = (tot + rec(next, moves, len - 1, dp)) % mod;
        }
        return dp[start][len] = tot;
    }
    int knightDialer(int n) {
        vector<int>moves[10] = {
            {4, 6},
            {6, 8},
            {7, 9},
            {8, 4},
            {0, 9, 3},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };
        int ans = 0;
        vector<vector<int>>dp(10, vector<int>(n + 1, -1));
        for(int i = 0; i <= 9; i++){
            ans = (ans + rec(i, moves, n, dp)) % mod;
        }
        return ans;
    }
};
class Solution {
public:
    int dp[100][101];
    int rec(int i, int& n, vector<vector<int>>& grid, int prev, int time){
        if(prev > time) return 1e9;
        if(prev == time) return 0;
        if(i >= n) return 1e9;
        if(dp[i][prev] != -1) return dp[i][prev];
        int len = 1e9;
        for(int j = grid[i][0]; j <= grid[i][1]; j++){
            if(j == prev){
                for(int k = j; k <= grid[i][1]; k++){
                    len = min(len, 1 + rec(i + 1, n, grid, k, time));
                }
            }
        }
        len = min(len, rec(i + 1, n, grid, prev, time));

        return dp[i][prev] = len;
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<tuple<int, int>>tup;
        for(vector<int>res : clips){
            tup.push_back({res[0], res[1]});
        }
        sort(tup.begin(), tup.end());
        vector<vector<int>>grid;
        int s = tup.size();
        for(int i = 0; i < s; i++){
            auto[st, et] = tup[i];
            grid.push_back({st, et});
        }
        memset(dp, -1, sizeof(dp));
        int ans = rec(0, s, grid, 0, time);
        return ans >= 1e8 ? -1 : ans;
    }
};
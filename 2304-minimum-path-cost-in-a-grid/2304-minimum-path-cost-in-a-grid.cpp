class Solution {
public:
    int rec(int i, vector<vector<int>>&values, unordered_map<int, int>& mp, vector<int>& dp){
        if(mp.find(i) != mp.end()) return i;
        if(dp[i] != -1) return dp[i];
        int cost = i;
        int ans = 1e9;
        for(int j = 0; j < values[i].size(); j++){
            if(values[i][j] == 0) continue;
            int val = values[i][j] + rec(j, values, mp, dp);
            ans = min(ans, cost + val);
        }
        return dp[i] = ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>values(m * n, vector<int>(m * n));
        for(int i = 0; i < m - 1; i++){
            for(int j = 0 ; j < n; j++){
                for(int k = 0; k < grid[i + 1].size(); k++){
                    values[grid[i][j]][grid[i + 1][k]] = moveCost[grid[i][j]][k];
                }
            }
        }
        vector<int>dp(m * n, -1);
        unordered_map<int, int>mp;
        for(int j = 0; j < n; j++){
            mp[grid[m - 1][j]]++;
        }
        int ans = 1e9;
        for(int j = 0; j < n; j++){
            ans = min(ans, rec(grid[0][j], values, mp, dp));
        }
        return ans;
    }
};
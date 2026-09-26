class Solution {
public:
    bool rec(int i, int k, vector<int>& stones, unordered_map<int, int>& mp, int& n, vector<vector<int>>& dp){
        if(i == n - 1) return true;
        if(i >= n) return false;
        if(dp[i][k] != -1) return dp[i][k];
        bool ans = false;
        if(i == 0){
            if(mp.find(stones[0] + 1) != mp.end()){
                ans = ans || rec(mp[stones[0] + 1], 1, stones, mp, n, dp);
            }
        }
        else{
            for(int j = k - 1; j <= k + 1; j++){
                if(mp.find(stones[i] + j) != mp.end() && i < mp[stones[i] + j]){
                    ans = ans || rec(mp[stones[i] + j], j, stones, mp, n, dp);
                }
            }
        }
        return dp[i][k] = ans;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int, int>mp;
        int n = stones.size();
        for(int i = 0; i < n; i++){
            mp[stones[i]] = i;
        }
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        return rec(0, 1, stones, mp, n, dp);
    }
};
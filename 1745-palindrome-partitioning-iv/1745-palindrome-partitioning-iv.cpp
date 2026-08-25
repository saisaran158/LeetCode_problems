class Solution {
public:
    bool palin(int i, int j, string& s){
        if(i == j) return true;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool solve(int i, int& n, string& s, int parts, vector<vector<int>>& dp){
        if(i == n && parts == 3) return true;
        if(parts == 3) return false;
        if(dp[i][parts] != -1) return dp[i][parts];
        bool ans = 0;
        for(int j = i; j < n; j++){
            if(palin(i, j, s)){
                ans = ans || solve(j + 1, n, s, parts + 1, dp);
            }
        }
        return dp[i][parts] = ans;
    }
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>>dp(n + 1, vector<int>(3, -1));
        return solve(0, n, s, 0, dp);
    }
};
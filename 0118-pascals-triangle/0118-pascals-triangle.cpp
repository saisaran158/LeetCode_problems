class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>dp;
        for(int i = 0; i < n; i++){
            vector<int>row(i + 1);
            for(int j = 0; j <= i; j++){
                if(j == 0) row[j] = 1;
                else if(j == i) row[j] = 1;
                else row[j] = 0;
            }
            dp.push_back(row);
        }
        for(int i = 2; i < n; i++){
            for(int j = 1; j < dp[i].size() - 1; j++){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        return dp;
    }
};
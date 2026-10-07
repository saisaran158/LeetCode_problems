class Solution {
public:
    int mod = 1e9 + 7;
    int dp[100][2][2][11];
    int rec(int i, int size, string& nums, bool tight, bool lz, int prev){
        if(i == size){
            if(!lz) return 1;
            return 0;
        }
        if(dp[i][tight][lz][prev] != -1) return dp[i][tight][lz][prev];
        int ans = 0;
        int up = tight ? nums[i] - '0' : 9;
        for(int dig = 0; dig <= up; dig++){
            if(lz && dig == 0){
                ans = (ans + rec(i + 1, size, nums, 0, 1, prev)) % mod;
            }
            else if(prev == 10 || abs(prev - dig) == 1){
                ans = (ans + rec(i + 1, size, nums, (tight && dig == up), (lz && dig == 0), dig)) % mod;
            }
        }
        return dp[i][tight][lz][prev] = ans % mod;
    }
    int countSteppingNumbers(string low, string high) {
        int i = low.size() - 1;
        while(low[i] == '0'){
            low[i] = '9';
            i--;
        }
        low[i]--;
        memset(dp, -1, sizeof(dp));
        int b = rec(0, high.size(), high, 1, 1, 10) % mod;
        memset(dp, -1, sizeof(dp));
        int a = rec(0, low.size(), low, 1, 1, 10) % mod;
        return ((b - a) + mod ) % mod;
    }
};
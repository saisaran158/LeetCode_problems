class Solution {
public:
    int mod = 1e9 + 7;
    int dp[23][2][2][401];
    int rec(int i, int size, string& nums, bool tight, bool lz, int sum, int& mn, int& mx){
        // cout << sum << " ";
        if(i == size){
            if(mn <= sum && sum <= mx){
                // cout << sum << " ";
                return 1;
            }
            return 0;
        }
        if(dp[i][tight][lz][sum] != -1) return dp[i][tight][lz][sum];

        int ans = 0;
        int up = (tight) ? nums[i] - '0' : 9;
        for (int j = 0; j <= up; j++){
            if(lz && j == 0){
                ans = (ans + rec(i + 1, size, nums, 0, 1, sum, mn, mx)) % mod;
            }
            else if(sum + j <= mx){
                ans = (ans + rec(i + 1, size, nums, (tight && j == up), (lz && j == 0), sum + j, mn, mx)) % mod;
            }
        }

        return dp[i][tight][lz][sum] = ans % mod;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int i = num1.size() - 1;
        while(num1[i] == 0){
            num1[i] = 9;
            i--;
        }
        num1[i]--;
        memset(dp, -1, sizeof(dp));
        int b = rec(0, num2.size(), num2, 1, 1, 0, min_sum, max_sum);
        memset(dp, -1, sizeof(dp));
        int a = rec(0, num1.size(), num1, 1, 1, 0, min_sum, max_sum);
        return ((b - a) + mod) % mod;
    }
};
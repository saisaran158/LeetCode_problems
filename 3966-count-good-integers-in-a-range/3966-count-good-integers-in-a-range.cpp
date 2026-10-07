class Solution {
public:
    long long dp[16][2][2][11];
    long long rec(int i, int size, string& nums, bool tight, bool lz, int prev, int k){
        if(i == size){
            if(!lz) return 1;
            return 0;
        }
        if(dp[i][tight][lz][prev] != -1) return dp[i][tight][lz][prev];
        long long ans = 0;
        int up = (tight == true) ? nums[i] - '0' : 9;
        for(int digit = 0; digit <= up; digit++){
            if(lz && digit == 0){
                ans += rec(i + 1, size, nums, 0, lz, prev, k);
            }
            else if(prev == 10 || abs(prev - digit) <= k){
                ans += rec(i + 1, size, nums, (tight && digit == up), (lz && digit == 0), digit, k);
            }
        }

        return dp[i][tight][lz][prev] = ans;

    }
    long long goodIntegers(long long l, long long r, int k) {
        string second = to_string(r);
        string first = to_string(l - 1);
        memset(dp, -1, sizeof(dp));
        long long b = rec(0, second.size(), second, 1, 1, 10, k);
        memset(dp, -1, sizeof(dp));
        long long a = rec(0, first.size(), first, 1, 1, 10, k);
        return b - a;
    }
};
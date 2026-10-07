class Solution {
public:
    int dp[10][2][2][20][21];
    int rec(int i, int size, string& nums, bool tight, bool lz, int& k, int rem, int count){
        if(i == size){
            if(count == 0 && rem == 0){
                return 1;
            }
            return 0;
        }
        if(dp[i][tight][lz][rem][count + 10] != -1) return dp[i][tight][lz][rem][count + 10];
        int ans = 0;
        int up = (tight == true) ? nums[i] - '0' : 9;
        for(int digit = 0; digit <= up; digit++){
            if(lz && digit == 0){
                ans += rec(i + 1, size, nums, 0, 1, k, rem, count);
            }
            else{
                ans += rec(i + 1, size, nums, (tight && digit == up), (lz && digit == 0), k, (rem * 10 + digit) % k, digit % 2 == 0 ? count + 1 : count - 1);
            }
        }
        return dp[i][tight][lz][rem][count + 10] = ans;

    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string second = to_string(high);
        string first = to_string(low - 1);
        memset(dp, -1, sizeof(dp));
        int b = rec(0, second.size(), second, 1, 1, k, 0, 0);
        memset(dp, -1, sizeof(dp));
        int a = rec(0, first.size(), first, 1, 1, k, 0, 0);
        return b - a;
    }
};
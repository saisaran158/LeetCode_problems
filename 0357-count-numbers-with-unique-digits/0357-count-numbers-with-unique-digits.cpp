class Solution {
public:
    int rec(int i, int size, string& nums, bool tight, bool lz, int mask){
        if(i == size){
            if(!lz) return 1;
            return 0;
        }

        int ans = 0;
        int up = tight ? nums[i] - '0' : 9;
        for(int j = 0; j <= up; j++){
            if(lz && j == 0){
                ans += rec(i + 1, size, nums, 0, lz, mask);
            }
            else{
                int check = mask >> j & 1;
                if(!check){
                    ans += rec(i + 1, size, nums, (tight && j == up), (lz && j == 0), mask | (1 << j));
                }
            }
        }
        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        int num = pow(10, n);
        string nums = to_string(num);
        return rec(0, nums.size(), nums, 1, 1, 0) + 1;
    }
};
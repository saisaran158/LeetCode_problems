class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>freq(32, 0);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 31; j >= 0; j--){
                if(nums[i] >> j & 1){
                    freq[j]++;
                }
            }
        }
        int sum = 0;
        int mod = 1e9 + 7;
        while(k--){
            long long curr = 0;
            for(int i = 0; i < 32; i++){
                if(freq[i] > 0){
                    curr |= 1 << i;
                    freq[i]--;
                }
            }
            sum = (sum + (curr * curr) % mod) % mod;
        }
        return sum;
    }
};
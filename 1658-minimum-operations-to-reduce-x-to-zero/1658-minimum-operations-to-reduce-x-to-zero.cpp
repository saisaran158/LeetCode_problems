class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = total - x;
        int n = nums.size();
        int len = 1e9;
        int curr = 0;
        int left = 0;
        for(int right = 0; right < n; right++){
            curr += nums[right];
            while(curr > sum && left <= right){
                curr -= nums[left];
                left++;
            }
            if(sum  == curr){
                len = min(len,(n - (right - left + 1)));
            }
        }
        return len == 1e9 ? -1 : len;
    }
};
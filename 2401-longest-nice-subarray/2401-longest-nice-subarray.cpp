class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int maxLen = 0;
        int mask = 0;
        for(int right = 0; right < nums.size(); right++){
            while((mask & nums[right]) != 0){
                mask = mask ^ nums[left];
                left++;
            }
            mask = mask | nums[right];
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
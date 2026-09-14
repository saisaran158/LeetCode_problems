class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0;
        int left = 0;
        unordered_map<int, int>mp;
        for(int right = 0; right < nums.size(); right++){
            mp[nums[right]]++;
            while(mp[0] > 1){
                mp[nums[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }
};
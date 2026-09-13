class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char, int>mp;
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            while(mp.find(s[right]) != mp.end()){
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }
            mp[s[right]]++;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_set<char>set;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while(set.count(s[i])){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[i]);
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mp;
        for (char x : t) {
            mp[x]++;
        }
        int count = t.size();
        int left = 0;
        int c = 0;
        int ind;
        int minLen = 1e9;
        for (int right = 0; right < s.size(); right++) {
            if (mp[s[right]] > 0) {
                c++;
            }
            mp[s[right]]--;
            while (c == count) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    ind = left;
                }
                mp[s[left]]++;
                if (mp[s[left]] > 0) {
                    c--;
                }
                left++;
            }
        }
        return minLen == 1e9 ? "" : s.substr(ind, minLen);
    }
};
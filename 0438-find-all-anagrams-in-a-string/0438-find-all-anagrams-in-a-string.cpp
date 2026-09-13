class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size())
            return res;
        unordered_map<char, int> pMap;
        unordered_map<char, int> sMap;
        for (char x : p) {
            pMap[x]++;
        }
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            sMap[s[right]]++;
            if (right - left + 1 > p.size()) {
                sMap[s[left]]--;
                if (sMap[s[left]] == 0) {
                    sMap.erase(s[left]);
                }
                left++;
            }
            if (right - left + 1 == p.size()) {
                if(pMap == sMap){
                    res.push_back(left);
                }
            }
        }
        return res;

        return res;
    }
};
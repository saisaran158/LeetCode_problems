class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>sMap;
        unordered_map<char, int>tMap;
        for(char x : s1){
            sMap[x]++;
        }
        int left = 0;
        for(int right = 0; right < s2.size(); right++){
            tMap[s2[right]]++;
            if(right - left + 1 > s1.size()){
                tMap[s2[left]]--;
                if(tMap[s2[left]] == 0){
                    tMap.erase(s2[left]);
                }
                left++;
            }
            if(right - left + 1 == s1.size()){
                if(sMap == tMap){
                    return true;
                }
            }
        }
        return false;
    }
};
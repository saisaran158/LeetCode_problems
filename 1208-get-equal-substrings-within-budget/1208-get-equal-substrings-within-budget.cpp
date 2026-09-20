class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = 0;
        int left = 0;
        int cost = 0;
        for(int right = 0; right < s.size(); right++){
            cost += abs(t[right] - s[right]);
            while(cost > maxCost){
                cost -= abs(t[left] - s[left]);
                left++;
            }
            len = max(len, right - left + 1);
        }
        return len;
    }
};
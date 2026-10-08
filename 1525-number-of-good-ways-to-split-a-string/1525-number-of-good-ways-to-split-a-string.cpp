class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int>left;
        unordered_map<char, int>right;
        int c = 0;
        int n = s.size();
        vector<int>dpLeft(n + 1, -1);
        vector<int>dpRight(n + 1, -1);
        for(int i = 0; i < n; i++){
            left[s[i]]++;
            dpLeft[i] = left.size();
        }
        for(int i = n - 1; i >= 0; i--){
            right[s[i]]++;
            dpRight[i] = right.size();
        }
        for(int i = 0; i < n - 1; i++){
            if(dpLeft[i] == dpRight[i + 1]) c++;
        }
        return c;
    }
};
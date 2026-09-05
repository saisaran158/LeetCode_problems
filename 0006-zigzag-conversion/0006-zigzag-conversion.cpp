class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<pair<char, int>>vp;
        int ind = 0;
        bool up = true;
        bool down = false;
        for(int i = 0; i < s.size(); i++){
            vp.push_back({s[i], ind});
            if(ind == numRows - 1){
                down = true;
                up = false;
            }
            if(ind == 0){
                up = true;
                down = false;
            }
            if(up){
                ind++;
            }
            else if(down){
                ind--;
            }
        }
        string res = "";
        for(int i = 0; i < numRows; i++){
            for(auto l : vp){
                if(l.second == i){
                    res += l.first;
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        int row = m - 1;
        int col = n;
        int col1 = n - 1;
        string t = "";
        string r = "";
        while(col--){
            r += '.';
        }
        ans.push_back(r);
        while(col1--){
            t += '#';
        }
        t += '.';
        while(row--){
            ans.push_back(t);
        }
        return ans;
    }
};
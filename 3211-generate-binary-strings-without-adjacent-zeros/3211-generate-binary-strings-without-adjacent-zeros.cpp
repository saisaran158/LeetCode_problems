class Solution {
public:
    void rec(int n, int prev, string path, vector<string>&res){
        if(path.size() == n){
            res.push_back(path);
            return;
        }

        if(prev == 2 || prev != 0){
            rec(n, 0, path + '0', res);
        }
        rec(n, 1, path + '1', res);
    }
    vector<string> validStrings(int n) {
       vector<string>res;
       rec(n, 2, "", res); 
       return res;
    }
};
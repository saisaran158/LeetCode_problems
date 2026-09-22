class Solution {
public:
    void rec(int start, int n, int k, vector<int> path, vector<vector<int>>& res){
        if(path.size() == k){
            res.push_back(path);
            return;
        }

        for(int i = start; i <= n; i++){
            path.push_back(i);
            rec(i + 1, n, k, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>path;
        rec(1, n, k, path, res);
        return res;
    }
};
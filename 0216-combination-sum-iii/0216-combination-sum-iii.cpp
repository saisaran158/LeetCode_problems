class Solution {
public:
    void recursion(int i, int j, int k, int n, vector<vector<int>>& res,
                   vector<int> path, int sum) {
        if (sum > n)
            return;
        if (path.size() == k) {
            if (sum == n) {
                res.push_back(path);
            }
        }
        for (int l = i; l <= j; l++) {
            path.push_back(l);
            recursion(l + 1, j, k, n, res, path, sum + l);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        recursion(1, 9, k, n, res, path, 0);
        return res;
    }
};
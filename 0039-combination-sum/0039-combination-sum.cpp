class Solution {
public:
    void ccs(int ind, vector<vector<int>> &res, vector<int>&ds, vector<int>& candidates, int target){
        if(ind == candidates.size()){
            if(target == 0){
            res.push_back(ds);
            }
            return;
        }
        if(candidates[ind] <= target){
            ds.push_back(candidates[ind]);
            ccs(ind, res, ds, candidates, target - candidates[ind]);
            ds.pop_back();
        }
        ccs(ind + 1, res, ds, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>>res;
      vector<int>ds;
      ccs(0, res, ds, candidates, target);
      return res;  
    }
};
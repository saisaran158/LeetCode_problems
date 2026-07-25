class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(auto it : nums){
            auto pos = lower_bound(res.begin(), res.end(), it);
            if(res.end() == pos)
            res.push_back(it);
            else{
                int ind = pos - res.begin();
                res[ind] = it;
            }
        }
        return res.size();
    }
};
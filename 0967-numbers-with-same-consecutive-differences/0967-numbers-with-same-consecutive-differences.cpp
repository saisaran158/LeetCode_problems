class Solution {
public:
    void rec(int i, int n, int k, string nums, vector<int>& res){
        if(i == n){
            res.push_back(stoi(nums));
            return;
        }

        for(int j = 0; j <= 9; j++){
            if(nums.size() == 0 && j == 0) continue;
            if(nums.size() == 0){
                rec(i + 1, n, k, nums + to_string(j), res);
            }
            else{
                if(abs((nums[nums.size() - 1] - '0') - j) == k)
                rec(i + 1, n, k, nums + to_string(j), res);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        rec(0, n, k, "", res);
        return res;
    }
};
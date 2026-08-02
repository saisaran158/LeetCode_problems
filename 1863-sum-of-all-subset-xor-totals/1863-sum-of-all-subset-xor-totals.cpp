class Solution {
public:
    void recursion(int ind, int sum, vector<int>& nums, int n, int& ans){
        if(ind == n){
            ans += sum;
            return;
        }

        recursion(ind + 1, sum ^ nums[ind], nums, n, ans);

        recursion(ind + 1, sum, nums, n, ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        recursion(0, 0, nums, n, ans);
        return ans;
    }
};
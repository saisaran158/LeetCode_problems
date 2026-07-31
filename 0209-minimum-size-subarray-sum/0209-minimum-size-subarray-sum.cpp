class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int ln = INT_MAX;
        int sum = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum >= target){
                ln = min(ln, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return ln == INT_MAX ? 0 : ln;
    }
};
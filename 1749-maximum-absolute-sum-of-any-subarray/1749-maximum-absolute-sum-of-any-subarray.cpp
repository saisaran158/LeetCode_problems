class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum < 0){
                sum = 0;
            }
            maxi = max(maxi, sum);
        }
        int maxy = 1e9;
        sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > 0){
                sum = 0;
            }
            maxy = min(maxy, sum);
        }
        return maxi >= abs(maxy) ? maxi : abs(maxy);
    }
};
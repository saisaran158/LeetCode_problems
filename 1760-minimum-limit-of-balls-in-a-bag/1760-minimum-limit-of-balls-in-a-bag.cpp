class Solution {
public:
    bool check(vector<int>& nums, int& maxOperations, int mid){
        unsigned long long c = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > mid && nums[i] % mid != 0){
                c = c + nums[i] / mid;
            }
            else if(nums[i] > mid && nums[i] % mid == 0){
                c = c + nums[i] / mid - 1;
            }
        }
        return c <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int low = 1;
        int high = -1e9;
        for(int i = 0; i < n; i++){
            if(nums[i] > high){
                high = nums[i];
            }
        }
        int mid;
        int ans;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(nums, maxOperations, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;


    }
};
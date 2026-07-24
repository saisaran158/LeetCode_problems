class Solution {
public:
    int lowerBound(vector<int> &nums, int target){
        int ans = -1;
        int low = 0;
        int high = nums.size() -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int> &nums, int target){
        int ans = -1;
        int low = 0;
        int high = nums.size() -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int ansl = -1;
        int ansh = -1;
        ansl = upperBound(nums, target);
        ansh = lowerBound(nums, target);
        return{ansl, ansh};
    }
};
class Solution {
public:
    bool check(vector<int>& nums, int& threshold, int mid){
        int sum = 0;
        for(int x : nums){
            if(x % mid == 0){
                sum += x / mid;
            }
            else{
                sum += (x / mid) + 1;
            }
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        int mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(nums, threshold, mid)){
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
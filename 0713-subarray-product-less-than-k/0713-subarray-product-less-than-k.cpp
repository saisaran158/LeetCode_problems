class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int pro = 1;
        int left = 0;
        int count = 0;
        for(int right = 0; right < nums.size(); right++){
            pro *= nums[right];
            while(pro >= k && left < nums.size()){
                pro /= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};
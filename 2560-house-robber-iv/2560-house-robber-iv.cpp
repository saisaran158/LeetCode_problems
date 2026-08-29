class Solution {
public:
    bool check(vector<int>& nums, int& k, int mid) {
        int c = 0;
        for (int i = 0; i < nums.size();) {
            if (nums[i] <= mid) {
                c++;
                i += 2;
            } else {
                i++;
            }
        }
        return c >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int mid, ans;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (check(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
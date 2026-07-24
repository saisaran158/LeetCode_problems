class Solution {
public:
    int binarySearch(int left, int right, vector<int> &nums, int target){
        int mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1 ;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[left] < nums[mid]){
                int c = binarySearch(left, mid -1, nums, target);
                if(c == -1)left = mid + 1;
                else return c;
            }
            else{
                int f = binarySearch(mid + 1, right, nums, target);
                if(f == -1)right = mid - 1;
                else return f;
            }
        }
        return -1;
    }
};
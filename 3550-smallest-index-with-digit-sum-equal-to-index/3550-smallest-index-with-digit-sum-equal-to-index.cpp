class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int d=0;
            while(nums[i]){
                d+=nums[i]%10;
                nums[i]/=10;
            }
            if(d==i)
            return i;
        }
        return -1;
    }
};
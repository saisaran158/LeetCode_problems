class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            set<int>sets;
            for(int j = i; j < n; j++){
                sets.insert(nums[j]);
                sum += sets.size() * sets.size();
            }
        }
        return sum;
    }
};
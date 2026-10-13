class Solution {
public:
    long long maxAlternatingSum(vector<int>& dup) {
        long long sum = 0;
        vector<int>nums;
        for(int i = 0; i < dup.size(); i++){
            nums.push_back(abs(dup[i]));
        }
        sort(nums.begin(), nums.end());
        int s = nums.size() / 2;
        for(int i = 0; i < s; i++){
            sum -= (nums[i] * nums[i]);
        }
        cout << sum << endl;
        for(int j = s; j < nums.size(); j++){
            sum += (nums[j] * nums[j]);
        }
        return sum;
    }
};
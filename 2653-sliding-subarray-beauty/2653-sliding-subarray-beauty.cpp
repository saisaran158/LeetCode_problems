class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int, int>mp;
        vector<int>res;
        int left = 0;
        int n = nums.size();
        for(int right = 0; right < n; right++){
            if(nums[right] < 0)
            mp[nums[right]]++;
            if((right - left + 1) > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            if((right - left + 1) == k){
                int freq = 0;
                int flag = 0;
                for(auto it : mp){
                    freq += it.second;
                    if(freq >= x){
                        res.push_back(it.first);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    res.push_back(0);
                }
            }
        }
        return res;
    }
};
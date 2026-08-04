class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ress;
        int a=nums[0];
        int b=nums[nums.size()-1];
        vector<int>res;
        for(int i=a;i<=b;i++){
            res.push_back(i);
        }
        for(int i=0;i<res.size();i++){
            int flag=0;
            for(int j=0;j<nums.size();j++){
                if(res[i]==nums[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                ress.push_back(res[i]);
            }
        }
        return ress;
    }
};
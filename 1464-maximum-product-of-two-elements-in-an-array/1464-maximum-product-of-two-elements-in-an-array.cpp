class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>a;
        for(int i=0;i<nums.size();i++){
            a.push_back(nums[i]-1);
        }
        int max=0;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a.size();j++){
                if(i!=j&&max<=a[i]*a[j]){
                    max=a[i]*a[j];
                }
            }
        }
        return max;
    }
};
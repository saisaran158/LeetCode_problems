class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
        for(int i=0;i<nums.size();i++){
            if(n%(i+1)==0){
                a.push_back(nums[i]);
            }
        }
        int sum=0;
        for(int i=0;i<a.size();i++){
            sum+=a[i]*a[i];
        }
        return sum;
    }
};
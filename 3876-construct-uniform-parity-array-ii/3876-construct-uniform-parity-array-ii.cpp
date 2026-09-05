class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int miny = 1e9;
        int flag = 0;
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i] < miny){
                miny = nums1[i];
            }
            if(nums1[i] % 2 == 1){
                flag = 1;
            }
        }
        if(miny % 2 == 0 && flag == 1){
            return false;
        }
        return true;
    }
};
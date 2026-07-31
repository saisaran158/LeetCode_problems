class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int water = 0;
        int rmax = INT_MIN;
        int lmax = INT_MIN;
        while(l < r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax <= rmax){
                water += lmax - height[l];
                l++;
            }

            else{
                water += rmax - height[r];
                r--;
            }
        }
        return water;
    }
};
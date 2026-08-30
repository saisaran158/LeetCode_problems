class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int mx = -1e9;
        int mn = 1e9;
        int tot = 0;
        int mxi;
        int mni;
        for (int i = 0; i < n; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                mxi = i;
            }
            if (nums[i] < mn) {
                mn = nums[i];
                mni = i;
            }
        }
        int c = max(mxi, mni) + 1;
        int d = n - min(mxi, mni);
        int e = n - (max(mxi, mni) - min(mxi, mni) - 1);
        cout <<"c :" << c;
        cout <<"d :" << d;
        cout <<"e :" << e;
        return min({c, d, e});
    }
};
class Solution {
public:
    int lrec(int i, vector<int>& arr, int& n){
        if(i == 0) return 0;

        int ans = 0;
        if(arr[i - 1] < arr[i])
        ans = 1 + lrec(i - 1, arr, n);
        return ans;
    }
    int rrec(int i, vector<int>& arr, int& n){
        if(i == n - 1) return 0;

        int ans = 0;
        if(arr[i + 1] < arr[i])
        ans = 1 + rrec(i + 1, arr, n);
        return ans;
    }
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 1; i < n - 1; i++){
            int left = lrec(i, arr, n);
            int right = rrec(i, arr, n);
            if(left != 0 && right != 0)
            ans = max(ans, left + right + 1);
        }
        return ans;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int left = 0;
        int res = 0;
        for(int right = 0; right < arr.size(); right++){
            sum += arr[right];
            if(right - left + 1 > k){
                sum -= arr[left];
                left++;
            }
            if(right - left + 1 == k && sum / k >= threshold){
                res++;
            }
        }
        return res;
    }
};
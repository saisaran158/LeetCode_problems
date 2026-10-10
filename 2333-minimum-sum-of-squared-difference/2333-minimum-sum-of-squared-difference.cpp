class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long>freq(100001, 0);
        int maxFreq = 0;
        int n = nums1.size();
        for(int i = 0; i < n; i++){
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            maxFreq = max(maxFreq, d);
        }
        long long k = k1 + k2;
        for(int d = maxFreq; d > 0 && k > 0; d--){
            int sub = k > freq[d] ? freq[d] : k;
            freq[d] -= sub;
            freq[d - 1] += sub;
            k -= sub;
        }

        long long ans = 0;
        for(long long i = 1; i <= maxFreq; i++){
            ans += (i * i) * freq[i];
        }
        return ans;
    }
};
class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isPrime(n + 1, true);
        if(n >= 0){
            isPrime[0] = false;
            isPrime[1] = false;
        }
        for(long long i = 2; i * i < n; i++){
            if(isPrime[i]){
                for(long long j = i * i; j < n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        // for(int i = 0; i < isPrime.size(); i++){
        //     if(isPrime[i] == true) cout << i << " ";
        // }
        int c = 0;
        for(int i = 2; i < n; i++){
            if(!isPrime[i]) continue;
            c++;
        }
        return c;
    }
};
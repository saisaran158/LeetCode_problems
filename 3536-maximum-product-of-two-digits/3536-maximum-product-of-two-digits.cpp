class Solution {
public:
    int maxProduct(int n) {
        vector<int>res;
        while(n){
            res.push_back(n%10);
            n/=10;
        }
        reverse(res.begin(),res.end());
        int max=0;
        for(int i=0;i<res.size()-1;i++){
            for(int j=i+1;j<res.size();j++){
                int pro=res[i]*res[j];
                if(pro>max){
                    max=pro;
                }
            }
        }
        return max;
    }
};
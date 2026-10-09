class NumArray {
public:
    vector<int>fenwick;
    vector<int>org;
    int n;
    NumArray(vector<int>& nums) {
        this -> org = nums;
        n = nums.size();
        fenwick.assign(n + 1, 0);
        for(int i = 0; i < n; i++){
            build(i, org[i]);
        }
    }
    void build(int ind, int val) {
        int i = ind + 1;
        while(i <= n){
            fenwick[i] += val;
            i += (i & (-i));
        }
    }
    void update(int ind, int val){
        int diff = val - org[ind];
        int j = ind + 1;
        while(j <= n){
            fenwick[j] += diff;
            j += j & (-j);
        }
        org[ind] = val;
    }
    int sum(int ind){
        int s = 0;
        int j = ind + 1;
        while(j > 0){
            s += fenwick[j];
            j -= (j & (-j));
        }
        return s;
    }
    int sumRange(int left, int right) {
        return sum(right) - sum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
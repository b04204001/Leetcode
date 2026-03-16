class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n > 0) {
            if (n & 1) ans++;
            n >>= 1;
        }
        return ans;
    }
};
//上面mask做法，記錄用&1

class Solution {
public:
    int hammingWeight(int n) {
        int count= 0;
        while( n!= 0){
            n = n & (n-1);
            count++;
        }
        return count;
    }
};
//直接用 n & n-1 =0 把1削掉看做幾次

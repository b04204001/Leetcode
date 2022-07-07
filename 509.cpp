20220706
  class Solution {
public:
    int fib(int n) {
        int ans;
        ans = FIB(n);
        return ans;
    }
    int FIB(int n){
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        return FIB(n-1) + FIB(n-2);
    }
};

class Solution {
public:
    int climbStairs(int n) {
        int A[46];
        A[0] = 0;
        A[1] = 1;
        A[2] = 2;
        //A[3] = 3;
        //A[4] = 5
        //A[5] =  1 +4 +3 =8
        for(int i=3;i<=n;i++){
            A[i] = A[i-1] +A[i-2];
        }
        return A[n];
    }
};


//遞迴法
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

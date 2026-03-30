class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt=0;
        while( left != right){
            left >>=1;
            right >>=1;
            cnt++;
        }
        return left << cnt;
    }
};
//概念: 找共同前綴，所以同時右移植到相同就會是&剩下的

//法2 
//留下共同前綴，只要讓right一直把1削掉，直到小於left就代表找到了

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right &= (right - 1);
        }
        return right;
    }
};

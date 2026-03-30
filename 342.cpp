class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while((n & 3 ) == 0){
            n>>=2;
        }
        return n == 1;
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if ((n & (n - 1)) != 0) return false;
        return (n - 1) % 3 == 0;
    }
};



class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n<=0) return false;
        if(n==1) return true;
        //只有一個1，在3.5.7 ....
        if(( n & (n-1)) !=0 ) return false;
        else{
            n>>=1;
            while(n>0){
                if( (n & 1 ) != 0 ) return false;
                n>>=2;
            }
        }
        return true;
    }
};

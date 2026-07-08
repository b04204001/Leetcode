class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long ans = 0;
        int cnt = 0;
        while(n > 0){
            if( n % 10 != 0){
                ans += (n % 10) * pow(10,cnt);
                sum += n % 10;
                cnt++;
            }
            n /= 10;
        }
        return ans * sum;
    }
};

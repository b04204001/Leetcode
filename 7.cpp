class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        bool neg = false;
        if ( x < 0){
            neg = true;
            if( x == INT_MIN) return 0;
            x *= -1 ;
        }
        while(x > 0){
            ans*=10;
            ans+= (x%10);
            x /=10;
        }
        if( ans > INT_MAX) return 0;
        return neg ?  -1 * ans : ans;
    }
};

//更好的寫法
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int pop = x % 10; // 支援負數，例如 -123 % 10 = -3
            x /= 10;
            
            // 溢位超前部署檢查（最優解的核心）
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) return 0;
            
            ans = ans * 10 + pop;
        }
        return ans;
    }
};

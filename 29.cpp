class Solution {
public:
    int divide(int dividend, int divisor) {
        // 1. 防禦 INT_MIN 溢位的超級特例
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // 2. 你的神來一筆：用 XOR 判斷結果是不是負數
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // 3. 轉成 long long 絕對值，徹底避開 abs(INT_MIN) 會當機的問題
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        long long ans = 0;

        // 4. 外層迴圈：只要被除數還夠大，就繼續減
        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1; // 記錄目前是幾倍

            // 內層迴圈：倍增探索！只要兩倍的除數還塞得下，就繼續翻倍 (左移)
            while (dvd >= (temp << 1)) {
                temp <<= 1;     // 除數翻倍 (相當於 * 2)
                multiple <<= 1; // 倍數也翻倍 (相當於 * 2)
            }

            // 把最大的倍數減掉，並把倍數加進答案裡
            dvd -= temp;
            ans += multiple;
        }

        // 5. 根據一開始記下的符號，還原正負號
        return isNegative ? -ans : ans;
    }
};

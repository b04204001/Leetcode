class Solution {
public:
    int findNthDigit(int n) {
        // 序列 1 : 9 2: 10 * 9 3: 100 * 9 4: 1000*9
        // 數字 9  90   900  9000...... pow(10, (i-1)) * 9 
        // 個數 9  180 2700 36000 ......  i * pow(10, (i-1)) * 9 
        int i = 1;
        //找出區段，第n個數字找出對應的區段i， 剩餘n在數幾個數字到目標
        while( (n > i * pow(10, i - 1) * 9)){
            n -= i * pow(10, (i-1)) * 9 ;
            i++;
        }
        // 2. 找出具體目標數字
        n--;  // 轉成 0-based
        long long start = pow(10, i - 1); //區段起點
        long long num = start + n / i;   // 第幾個數字
        int bit_idx = n % i;             // 該數字中的第幾位（從左到右）

        // 3. 找出那一位
        string s = to_string(num);
        return s[bit_idx] - '0';

    }
};




//優解
class Solution {
public:
    int findNthDigit(int n) {
        //長度，數字通常1~9 ， 從1開始
        long long len = 1, count = 9, start = 1;

        while (n > len * count) {
            n -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        n--;
        long long num = start + n / len;
        int idx = n % len;

        return to_string(num)[idx] - '0';
    }
};

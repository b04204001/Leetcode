

//憂解
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned carry = (unsigned)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};

// ^ 無進位加法  0^ 1 = 1^ 0 = 1 , 1^ 1 = 0
1 & 1 進位 -> 左移 << 1
做完變成 無進位加法結果 + 進位結果
在兩者相加，直到沒有進位就會得到成果，

Step 1: 無進位加法 → XOR
Step 2: 找進位 → AND << 1
Step 3: 把「進位」當成下一輪要加的數
Step 4: 重複直到進位為 0

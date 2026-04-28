int hammingDistance(int x, int y) {
    int cnt = 0;
    while(x >0 || y >0){
        int bit_a = 1 & x;
        int bit_b = 1 & y ;
        if((bit_a ^ bit_b) !=0) cnt++;
        x>>=1;
        y>>=1;
    }
    return cnt;
}

憂解
int hammingDistance(int x, int y) {
    int dist = 0;
    // 先做 XOR，找出所有不同的位元
    unsigned int n = x ^ y; 
    
    // 計算 n 裡面有多少個 1 (Popcount)
    while (n > 0) {
        n &= (n - 1); // 布萊恩·克尼漢演算法：每次消除最右邊的 1
        dist++;
    }
    return dist;
}

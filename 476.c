int findComplement(int num) {
    if (num == 0) return 1; // 邊界情況處理
    
    unsigned int mask = ~0; // 產生全 1 的位元 (1111...)
    
    // 透過迴圈將 mask 左移，直到與 num 的位數相同
    // 或者直接找出 num 的最高位並產生遮罩
    int temp = num;
    while (temp > 0) {
        temp >>= 1;
        mask <<= 1;
    }
    
    // 此時 mask 的低位為 0，高位為 1。取反後變成低位全 1。
    return ~mask ^ num;
}

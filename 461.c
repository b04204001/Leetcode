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

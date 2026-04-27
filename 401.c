/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countbit(int n){
    int cnt = 0;
    while(n >0){
        n &= (n-1);
        cnt++;
    }
    return cnt;
}
char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** ans = (char**)malloc(sizeof(char*) * 720);
    *returnSize = 0;
    for(int i = 0;i<12;i++){
        for(int j =0;j<60;j++){
            int n = countbit(i) + countbit(j);
            if(n == turnedOn){
                ans[*returnSize] = (char*)malloc(sizeof(char) * 6); // "HH:MM" 最長 5 字元 + '\0'
                // %d 是小時，%02d 是分鐘（不足兩位補 0）
                sprintf(ans[*returnSize], "%d:%02d", i,j);
                
                (*returnSize)++;
            }
        }
    }
    
    return ans;
}

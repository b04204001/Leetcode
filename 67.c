void reverse(char* a, int num){
    int l = 0;
    int r = num -1;
    while(l < r){
        char temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l++; 
        r--;
    }
}
char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    // 最大長度為兩者較長者 + 1 (進位) + 1 (\0)
    char* ans = (char*)malloc(sizeof(char) * (lenA > lenB ? lenA + 2 : lenB + 2));
    
    int i = lenA - 1;
    int j = lenB - 1;
    int carry = 0;
    int cnt = 0;

    // 當還有位數要算或還有進位時繼續
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        ans[cnt++] = (sum % 2) + '0'; // 存入目前的餘數
        carry = sum / 2;             // 計算進位
    }
    
    ans[cnt] = '\0';  // 放結束符號
    reverse(ans, cnt); // 翻轉回正確順序
    
    return ans;
}

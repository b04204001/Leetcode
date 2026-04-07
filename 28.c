int strStr(char* haystack, char* needle) {
    char * l = haystack;
    char * r = needle;
    int cnt = 0;
    int ans = 0;
    while(*l != '\0'){
        if(*l == *r){
            l++;
            r++;
            cnt++;
        }
        else{
            ans++;
            l = haystack + ans;
            cnt = ans;
            r = needle;
        }
        if(*r ==  '\0') return ans;
    }
    return -1;
}

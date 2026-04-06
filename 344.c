void reverseString(char* s, int sSize) {
    char* l = s;
    char* r = s + sSize -1 ;
    while(l < r){
        char t = *l;
        *l = *r;
        *r = t;
        l++;
        r--;
    }
}

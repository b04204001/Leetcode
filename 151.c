void reverse(char* s , char*e){
    while(s < e){
        char t = *s;
        *s = *e;
        *e = t;
        s++;
        e--;
    }
}

char* reverseWords(char* s) {
    char *read = s;
    char * write = s;
    //清理空格
    // 1. 去掉前導空白
    while (*read == ' ') read++;
    //2.中間
    while(*read){
        if(*read != ' '){
            *write++ = *read++;
        }
        else{
            *write++ = *read;
            while (*read == ' ') read++;
        }
    }
    //3.尾巴
    while (write > s && *(write-1) == ' ') write--;
    *write = '\0';
    //大反轉
    reverse(s,write - 1);

    //各自word反轉
    char* start = s;
    char* end = s;
    while(*end != '\0'){
        if(*end == ' '){
            reverse(start,end-1);
            end++;
            start = end;
        }
        else{
            end++;
        }
    }
    //最後一個word反轉
    reverse(start,end-1);
    return s;
}


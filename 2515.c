bool issame(char* a , char* b){
    while(*a != '\0' && *b != '\0'){
        if (*a != *b) return false;
        a++;
        b++;
    }
    return *a== '\0' && *b == '\0';
}

int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
    int min = INT_MAX;
    for(int i =0;i<wordsSize;i++){
        //if(words[i] == target){
        if(issame(words[i],target)){
            int disr = abs(i - startIndex);
            if (disr < min) min = disr;
            int disl =  wordsSize - abs(i - startIndex);
            if (disl < min) min = disl;
        }
    }
    return min == INT_MAX ? -1 : min;
}

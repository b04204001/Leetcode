class Solution {
public:
    int numberOfSpecialChars(string word) {
        int A[26] = {0};
        int a[26] = {0};
        int n = word.length();
        for(char c : word){
            if(c >= 'A' && c <= 'Z'){
                A[c - 'A']++;
            }
            else if (c >= 'a' && c <='z'){
                a[c - 'a']++;
            }
        }
        int sum = 0;
        for(int i = 0 ;i <26;i++){
            if(A[i] > 0 && a[i] > 0) sum++;
        }
        return sum;
    }
};

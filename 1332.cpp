20220608
class Solution {
public:
    int removePalindromeSub(string s) {
        int l= s.length();
        for(int i=0; i< l/2;i++ ){
            if(s[i] != s[l-1-i]){
                return 2;
            }
        }
        return 1;
    }
};

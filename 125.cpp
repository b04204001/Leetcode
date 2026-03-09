class Solution {
public:
    bool isPalindrome(string s) {
        int r = s.length() - 1;
        int l = 0;
        while(l <r ){
            if (!isalnum(s[r])) {
                r--;
            }
            else if(!isalnum(s[l])){
                l++;
            }
            else{
                //if(tolower(s[r]) != tolower(s[l])){
                if(abs(s[r]- s[l]) % 32 != 0){
                    return false;
                }
                r--;
                l++;
            }

        }
        return true;
    }
};

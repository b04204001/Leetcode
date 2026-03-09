class Solution {
public:
    bool isPalindrome(string s) {
        int r = s.length() - 1;
        int l = 0;
        while(l<=r ){
            if (!isalnum(s[r])) {
                r--;
            }
            else if(!isalnum(s[l])){
                l++;
            }
            else{
                if(tolower(s[r]) != tolower(s[l])){
                    return false;
                }
                r--;
                l++;
            }

        }
        return true;
    }
};



class Solution {
public:
    bool isPalindrome(string s) {
        int r = s.length() - 1;
        int l = 0;
        
        while (l < r) {
            if (!isalnum(s[r])) {
                r--;
            }
            else if (!isalnum(s[l])) {
                l++;
            }
            else {
                // 1. 把左右兩邊的字元先抓出來
                char left_c = s[l];
                char right_c = s[r];
                
                // 2. 【核心觀念：手刻 tolower】
                // 如果它是大寫字母 (介於 'A' 和 'Z' 之間)，我們就幫它 +32 變成小寫
                if (left_c >= 'A' && left_c <= 'Z') left_c += 32;
                if (right_c >= 'A' && right_c <= 'Z') right_c += 32;
                
                // 3. 轉完之後，直接用最簡單的 != 判斷就好！
                if (left_c != right_c) {
                    return false;
                }
                
                r--;
                l++;
            }
        }
        return true;
    }
};

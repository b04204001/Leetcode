class Solution {
public:

    int expand(string s,int i , int j){
        while( i >= 0 && j < s.length() && s[i] == s[j]){
            i--;
            j++;
        }
        return (j-1) - (i+1) + 1;
    }
    string longestPalindrome(string s) {
        int start = 0;
        int max_len = 0;
        for(int i =0;i<s.length();i++){
            int a = expand(s,i,i);
            if( a > max_len){
                start = i - a/2;
                max_len = a;
            }
            int b = expand(s,i,i+1);
            if(b > max_len){
                start = i - (b - 1) / 2;
                max_len = b;
            }
        }
        string ans="";
        for(int i = start ; i < start + max_len;i++ ){
            ans+= s[i];
        }
        return ans;
    }
};


//中心擴展法，另外紀錄最長並記錄開始結束，最後用substr回傳
class Solution {
public:
    int start = 0;
    int maxLen = 0;
    void expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int len = right - left + 1;
            //紀錄最長
            if (len > maxLen) {
                maxLen = len;
                start = left;
            }
            //擴展
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        for (int i = 0; i < s.length(); i++) {
            expand(s, i, i);     // 奇數
            expand(s, i, i + 1); // 偶數
        }

        return s.substr(start, maxLen);
    }
};

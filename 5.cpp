


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

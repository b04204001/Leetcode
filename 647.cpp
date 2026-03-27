class Solution {
public:
    int countsub(string s, int left ,int right){
        if( left <0 || right >= s.length() ) return 0;
        if( s[left] != s[right]) return 0;
        //目前字串已經是回文，往左右擴展
        return 1 + countsub(s,left-1,right+1);
    }
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += countsub(s,i,i) + countsub(s,i,i+1);
        }
        return ans;
    }
};


//中心擴展
因為回文分成奇數偶數，分為兩種狀況
(i,i)左右擴展 / (i,i+1)左右擴展
先決定中心，左右相等就會+1，然後再擴展，直到超出邊界 / 不同。

class Solution {
public:
    int expand(string& s, int left, int right) {
        int count = 0;

        // 只要左右還在範圍內，而且字元相同，就能形成回文
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            // 奇數長度回文，以 i 為中心
            ans += expand(s, i, i);

            // 偶數長度回文，以 i 和 i+1 中間為中心
            ans += expand(s, i, i + 1);
        }

        return ans;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string ans = s;
        //1.去除多餘空格
        //前空格，找到一個字母
        int read = 0;
        int write = 0;
        while(s[read] == ' ') read++;
        //中間空格
        while(s[read]){
            if(s[read] != ' '){
                s[write++] = s[read++];
            }
            else{
                s[write++] = s[read];
                while(s[read] == ' ') read++;
            }
        }
        //後空格
        while(write>0 && s[write-1] == ' ' ) write--;
        s.resize(write);
        //2.大反轉
        reverse(s.begin(),s.end());
        //3.局部反轉
        int start = 0;
        for (int i = 0; i <= s.length(); i++) {
            // 當遇到空格或到達字串結尾時，反轉前面的單字
            if (i == s.length() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};

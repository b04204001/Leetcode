class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(char c : s){
            if(c >= 'a' && c <= 'z') ans+=c;
            else if ( c == '#') {
                string r = ans;
                ans+=r;
            }
            else if ( c == '%'){
                reverse(ans.begin(),ans.end());
            }
            else if (c == '*'){
                if(ans.length() > 0) ans.pop_back(); 
            }
        }
        return ans;
    }
};

//更憂解
class Solution {
public:
    string processStr(string s) {
        string ans = "";
        
        long long count = 1;       // 当前字符的复制倍数
        bool is_reversed = false;  // 当前是否处于翻转状态
        long long skip = 0;        // 当前状态下需要跳过的字符数量

        // 从后往前逆向遍历
        for (int i = s.length() - 1; i >= 0; --i) {
            char c = s[i];

            if (c == '#') {
                // 遇到 #，后续所有字符的复制倍数翻倍
                count *= 2;
            } 
            else if (c == '%') {
                // 遇到 %，翻转状态取反
                is_reversed = !is_reversed;
            } 
            else if (c == '*') {
                // 遇到 *，意味着需要删除当前倍数个字符
                skip += count;
            } 
            else if (c >= 'a' && c <= 'z') {
                // 处理普通字母
                if (skip >= count) {
                    // 如果跳过计数器大于等于当前倍数，说明这些字母全被删除了
                    skip -= count;
                } else {
                    // 计算扣除删除后，实际存活的字母数量
                    long long actual_add = count - skip;
                    skip = 0; // 跳过计数器清空

                    // 构造需要构造的局部字符串
                    string temp(actual_add, c);
                    
                    // 根据翻转状态决定拼接到头部还是尾部
                    if (is_reversed) {
                        ans = ans + temp;
                    } else {
                        ans = temp + ans;
                    }
                }
            }
        }
        return ans;
    }
};

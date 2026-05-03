class Solution {
public:
    bool rotateString(string s, string goal) {
        int slen = s.length();
        int glen = goal.length();
        int j = 0;
        if(slen != glen )return false;

        for(int i = 0;i<slen;i++){
            j = 0;
            while(j<glen && s[k] == goal[j]){
                k++;
                j++;
                if(k == slen) k = 0;
            }
            if(j == glen ) return true;
        }
        return false;
    }
};

//更優
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        // 1. 長度不相等則不可能透過旋轉得到
        if (s.length() != goal.length()) {
            return false;
        }
        
        // 2. 檢查 goal 是否為 s + s 的子字串
        string doubled_s = s + s;
        return doubled_s.find(goal) != string::npos;
    }
};


//最優
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        // 1. 長度不相等直接防呆
        if (n != goal.length()) return false;
        if (n == 0) return true;

        int i = 0; // 追蹤 s 的起點
        int j = 0; // 追蹤 goal 的匹配進度
        int k = 0; // 記錄當前匹配了多少個字元

        // 最多只需要比對 2n 次（因為相當於在 s+s 中找 goal）
        while (i < n && j < 2 * n) {
            if (s[(i + k) % n] == goal[(j + k) % n]) {
                k++;
                if (k == n) return true; // 成功匹配 n 個字元
            } else {
                // 當發生不匹配時，我們利用貪心策略跳躍
                if (k == 0) {
                    j++; // 如果第一個字元就不對，goal 的指針往後移
                } else {
                    i += k; // s 的起點直接跳過已匹配的 k 個字元
                    k = 0;  // 歸零重新匹配
                }
            }
        }
        return false;
    }
};





概念:右指針負責擴張，直到窗口滿足條件；左指針負責收縮，讓窗口變最小。

class Solution {
public:
    string minWindow(string s, string t) {
        //紀錄t表
        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c]++;
        }

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;
        int need = t.size();

        for (int right = 0; right < s.size(); right++) {
            // 右指針納入新字元 
            if (mp[s[right]] > 0) {
                need--;
            }
            mp[s[right]]--;

            // 當前窗口已經滿足條件，開始縮左邊
            while (need == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                mp[s[left]]++;
                if (mp[s[left]] > 0) {
                    need++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

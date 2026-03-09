class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // 1. 防呆：如果輸入是空的，直接回傳空陣列
        if (digits.empty()) {
            return {};
        }
        
        // 2. 建立正確的手機鍵盤查表表 (注意 7 和 9 有四個字母)
        string sym[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        // 3. 初始化 ans，裡面先放一個空字串當作「種子」
        vector<string> ans;
        ans.push_back("");
        
        // 4. 開始走訪輸入的每一個數字
        for (int i = 0; i < digits.length(); i++) {
            
            // 抓出這個數字對應的字母，例如 '2' -> "abc"
            string letters = sym[digits[i] - '0'];
            
            // 準備一個臨時陣列來裝這一回合生出來的新組合
            vector<string> temp;
            
            // 雙重迴圈：把 ans 裡面舊的字串拿出來，配上新的字母
            for (string old_str : ans) {
                for (char c : letters) {
                    temp.push_back(old_str + c); // 組裝後塞進臨時陣列
                }
            }
            
            // 這回合結束，把臨時陣列的結果直接覆蓋掉舊的 ans
            ans = temp;
        }
        
        return ans;
    }
};

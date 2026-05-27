//正解
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;

        // 使用陣列代替雜湊表，效能更高（僅 26 個英文字母）
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        // 1. 統計 s1 的字母頻率，以及 s2 第一個視窗的字母頻率
        for (int i = 0; i < n1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        // 2. 滑動視窗比較
        for (int i = n1; i < n2; i++) {
            if (count1 == count2) return true;

            // 視窗向右移動：加入新字元，移除舊字元
            count2[s2[i] - 'a']++;       // 右邊界進入
            count2[s2[i - n1] - 'a']--;  // 左邊界離開
        }

        // 檢查最後一個視窗
        return count1 == count2;
    }
};

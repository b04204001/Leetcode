class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        //先計算好rows * cols
        int n = encodedText.length();
        int cols = n / rows;
        string ans = "";

        // 1. 遍歷第一列的每個字元作為「斜線起點」(0,0) ~ (0,cols)
        for (int j = 0; j < cols; ++j) {
            // 2. 從起點 (0, j) 開始往右下方移動
            // 每次 row+1, col+1，兩者增加的量相同，設為 i
            // 0,0 1,1 2,2 ...   0,1 1,2 2,3 ...
            for (int r = 0, c = j; r < rows && c < cols; ++r, ++c) {
                // 計算在一維字串中的位置
                ans += encodedText[r * cols + c];
            }
        }

        // 3. 移除末尾的空格 (Trailing spaces)
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};

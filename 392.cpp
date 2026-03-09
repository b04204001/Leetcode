class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0; 
        int q = 0; 
        
        // 【防護罩直接設在迴圈門口】
        // 只要有人走到盡頭，迴圈瞬間強制結束，絕對不可能越界！
        while (p < s.length() && q < t.length()) {
            
            // 如果配對成功，目標才往前走
            if (s[p] == t[q]) {
                p++;
            }
            
            // 【最關鍵的一步】：不管有沒有配對成功，長字串永遠都要往前走！
            // 這樣就解決了你「字元被重複利用」的問題
            q++;
        }
        
        // 迴圈結束後，看目標是不是全部找齊了
        return p == s.length();
    }
};

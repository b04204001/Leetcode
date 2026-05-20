class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> common;
        int n = A.size();
        int count[50] = {0};
        for(int i =0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j<=i;j++){
                count[A[j]]++;
            }
            for(int j = 0;j<=i;j++){
                if(count[B[j]] >0){
                    cnt++;
                    count[B[j]]--;
                }
            }
            common.push_back(cnt);
        }
        return common;
    }
};


//最優解
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> common;
        
        // 1. 宣告一個全域的計數陣列，大小為 n + 1，初始值都是 0
        // 它會隨著迴圈前進持續累積，不需要每輪重新計算
        vector<int> count(n + 1, 0); 
        
        int cnt = 0; // 記錄當前累積的共同數字數量

        // 2. 只用「一層」迴圈遍歷
        for (int i = 0; i < n; i++) {
            
            // 處理 A[i]：加 1
            count[A[i]]++;
            if (count[A[i]] == 0) { // 如果變回 0，代表跟之前的 B 配對成功
                cnt++;
            }

            // 處理 B[i]：減 1
            count[B[i]]--;
            if (count[B[i]] == 0) { // 如果變回 0，代表跟之前的 A 配對成功
                cnt++;
            }

            // 將當前的結果放入答案中
            common.push_back(cnt);
        }

        return common;
    }
};

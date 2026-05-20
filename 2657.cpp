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
        vector<int> common(n);
        vector<int> freq(n + 1, 0); // 題目給定數字範圍為 1 到 n
        int current_common = 0;

        for (int i = 0; i < n; i++) {
            // 處理陣列 A 的元素
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                current_common++;
            }

            // 處理陣列 B 的元素
            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                current_common++;
            }

            common[i] = current_common;
        }

        return common;
    }
};

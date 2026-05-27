class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        int A[26]={0};
        int a[26]={0};
        int cnt = 0;
        for(auto c : word){
            if(c >= 'a' && c <= 'z'){
                if(a[c-'a'] == -1) continue;
                else  if(A[c - 'a' ] == 1){
                    A[c - 'a'] = -1;
                    a[c-'a'] = -1;
                    cnt--;
                }
                else{
                    a[c - 'a'] = 1;
                }
            }
            else if (c >= 'A' && c <= 'Z' ){
                if(a[c-'A'] == -1) continue;
                else if(a[c - 'A'] == 1){
                    if(A[c-'A'] != 1){
                        A[c-'A'] = 1;
                        cnt++;
                    }
                }
                else{
                    A[c-'A'] = -1;
                    a[c-'A'] = -1;
                }
            }
        }
        return cnt;
    }
};

//最優解
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> last_lower(26, -1);
        vector<int> first_upper(26, -1);

        // 遍歷一次，單純記錄位置
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') {
                last_lower[c - 'a'] = i;    // 不斷覆蓋，得到「最後一次」
            } else {
                int idx = c - 'A';
                if (first_upper[idx] == -1) {
                    first_upper[idx] = i;   // 只記錄「第一次」
                }
            }
        }

        // 最後花 O(1) 的固定時間（迴圈 26 次）檢查答案
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (last_lower[i] != -1 && first_upper[i] != -1 && last_lower[i] < first_upper[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};



class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string w : words){
            int sum = 0;
            for(char c :w){
                sum += weights[ c - 'a'];
            }
            sum %= 26;
            ans += 'z' - sum;
        }
        return ans;
    }
};


//更憂解
class Solution {
public:
    string mapWordWeights(const vector<string>& words, const vector<int>& weights) {
        string ans;
        // 1. 預先配置記憶體，避免動態擴容的效能開銷
        ans.reserve(words.size()); 

        // 2. 使用常數引用 (const auto&)，避免複製字串
        for (const string& w : words) {
            int sum = 0;
            for (char c : w) {
                sum += weights[c - 'a'];
            }
            
            // 3. 確保餘數為正數（防止 weights 中有負數導致 sum % 26 為負）
            sum = (sum % 26 + 26) % 26; 
            
            // 4. 根據原邏輯映射至 'z' ~ 'a'
            ans.push_back('z' - sum);
        }
        return ans;
    }
};

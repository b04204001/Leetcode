class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        vector<int> ans;
        unordered_map<char,int> mp;
        bool isana = true;
        for(char c : p){
            mp[c]++;
        }
        for(int i =0;i<k;i++){
            mp[s[i]]--;
        }
        for(auto pair : mp){
            if(pair.second != 0){
                isana=false;
                break;
            }
        }
        if(isana) ans.push_back(0);
        for(int i= k; i < s.size()  ; i++){
            mp[s[i]]--;
            mp[s[i-k]]++;
            isana = true;
            for(auto pair : mp){
                if(pair.second != 0){
                    isana=false;
                    break;
                }
                
            }
            if(isana) ans.push_back(i-k+1);
        }
        return ans ;
    }
};

//優解
//因為是英文字母所以可以用26代替。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), k = p.size();
        if (n < k) return ans;

        vector<int> cntP(26, 0), cntS(26, 0);

        for (char c : p) {
            cntP[c - 'a']++;
        }

        // 第一個 window
        for (int i = 0; i < k; i++) {
            cntS[s[i] - 'a']++;
        }

        if (cntS == cntP) ans.push_back(0);

        // sliding window
        for (int i = k; i < n; i++) {
            cntS[s[i] - 'a']++;         // 新進來
            cntS[s[i - k] - 'a']--;     // 舊出去

            if (cntS == cntP) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};

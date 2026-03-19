class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> mp;
        for(char c :s){
            mp[c]++;
        }
        for(char c:t){
            mp[c]--;
        }
        // 拿出來的 pair 是一個實體，所以可以用「點」！
        for(auto const& pair : mp) {
            if(pair.second != 0){
                return false;
            }
        }

        return true;
    }
};

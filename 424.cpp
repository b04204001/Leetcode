class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int max_count = 0;
        int max_len = 0;
        int i = 0;
        for(int j = 0;j < s.length(); j++){
            mp[s[j]]++;
            max_count = max(max_count , mp[s[j]]);
            while( (j-i+1) - max_count > k ){
                mp[s[i]]--;
                i++;
            }
            max_len = max(max_len, j-i+1);
        }

        return max_len;
    }
};

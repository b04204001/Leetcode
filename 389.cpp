//hash
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map <char,int> mp;
        for( char c : s){
            mp[c] += 1;
        }
        for(char c : t){
            mp[c] -=1;
        }
        char ans ;
        for(auto const& pair : mp){
            if(pair.second != 0){
                ans += pair.first ;
            }
        }
        return ans;
    }
};

//bit
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0; // 0 是 XOR 的初始完美容器
        
        // 把 s 裡面的字元全部 XOR 進去
        for (char c : s) {
            ans ^= c;
        }
        
        // 把 t 裡面的字元也全部 XOR 進去
        for (char c : t) {
            ans ^= c;
        }
        
        // 活下來的那個就是答案！
        return ans;
    }
};

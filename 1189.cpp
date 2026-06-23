class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // balloon 
        unordered_map<char,int> mp;
        for(char a : text){
            mp[a]++;
        }
        int ans = INT_MAX;
        ans = min(ans, mp['b']);
        ans = min(ans, mp['a']);
        ans = min(ans, mp['l'] / 2);
        ans = min(ans, mp['o'] / 2);
        ans = min(ans, mp['n']);
        return ans;
    }
};

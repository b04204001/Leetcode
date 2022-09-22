class Solution {
public:
     string reverseWords(string s) {
        stringstream ss(s);
        string t, ans;   
        while (getline(ss, t, ' ')) {
            reverse(t.begin(), t.end());
            ans += t + ' ';
        }
        ans.substr();
        ans.resize(ans.size()- 1);
        return ans; 
    }
};

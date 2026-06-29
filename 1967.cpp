class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt= 0;
        for(string str: patterns){
            if(word.find(str) != string::npos) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        //用hash紀錄
        unordered_map<string,vector<string>> mp;
        for(string s : strs){
            string temp = s;
            //相同的sort結果會相同
            sort(temp.begin(),temp.end());
            //加到second
            mp[temp].push_back(s);
        }
        //遍歷hash，把second加到ans
        //for( pair<string, vector<string>> x : mp)
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

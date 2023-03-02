class Solution {
public:
    int compress(vector<char>& chars) {
        int n= chars.size();
        if(chars.empty()) return 0;
        char cur = chars[0];
        int count =1;
        string ans;
        for(int i=1;i<=n;i++){
            if(i < n && cur == chars[i] ){
                count++;
            }
            else{
                ans.push_back(cur);
                if (count > 1) {
                    string str = to_string(count);
                    for (char c : str) {
                        ans.push_back(c);
                    }
                }
                cur= i < n ? chars[i] :0;
                count =1;
            }       
        }
        for (int i = 0; i < ans.size(); i++) {
            chars[i] = ans[i];
        }
        return ans.size();
    }

};



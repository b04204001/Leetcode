class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        //放入hash
        unordered_map<string,int> hash;
        for(string s : words){
            hash[s]++;
        }
        // Step 2: max heap
        // 規則：
        // 1. 頻率高的優先
        // 2. 頻率相同時，字典序小的優先
        auto cmp = [](pair<string,int>& a, pair<string,int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;   // 字典序小的優先
            }
            return a.second < b.second;     // 頻率大的優先
        };
        /*
        //自己寫的
        auto cmp[] = (pair<string,int>& a, pair<string,int>& b) {
            return a.second < b.second;
        };
        */
        priority_queue< pair<string,int>, vector<pair<string,int>> ,decltype(cmp) > pq(cmp);
        for (auto& p : hash) {
            pq.push(p);
        }
        //取出最多的K個
        for(int i =0 ; i <k ;i++){
            pair<string,int> p = pq.top();
            ans.push_back(p.first);
            pq.pop();
        }
        return ans;
    }
};

//0409 daily
class Solution {
public:
    // 頻率當比較標準
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(auto i:nums) count[i]++;
        vector<pair<int,int>> cnt;
        for(auto i:count) cnt.push_back({i.first,i.second});
        sort(cnt.begin(),cnt.end(),cmp);
        vector<int> result;
        
        for(int i =0; i<k;i++){
            result.push_back(cnt[i].first);
        } 
        
        return result;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: 計算頻率
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: min heap（小頂堆）
        // pair<數字, 頻率>
        auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second; // 小的在上面
        };

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            decltype(cmp)
        > pq(cmp);

        // Step 3: 把元素丟進 heap
        for (auto& [num, count] : freq) {
            pq.push({num, count});

            // 如果超過 k，就把最小的丟掉
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Step 4: 把答案取出
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};

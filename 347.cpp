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

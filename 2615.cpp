class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& [val, pos] : mp) {
            int m = pos.size();
            long long total = 0;

            for (int p : pos) total += p;

            long long prefix = 0;
            for (int i = 0; i < m; i++) {
                long long cur = pos[i];

                long long left = cur * i - prefix;
                long long right = (total - prefix - cur) - cur * (m - 1 - i);

                ans[cur] = left + right;

                prefix += cur;
            }
        }

        return ans;
    }
};

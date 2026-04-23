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
            //比i小的總和
            long long prefix = 0;
            for (int i = 0; i < m; i++) {
                long long cur = pos[i];
                // 拆分左右，並拆開abs， | a - b| = b - a 左邊，b較大，這邊是第i個
                long long left = cur * i - prefix;
                // 拆分左右，並拆開abs， | a - b| = a - b 右邊，a較小，這邊是後面 m - (i + 1)，total是所有index總和，
                long long right = (total - prefix - cur) - cur * (m - 1 - i);

                ans[cur] = left + right;

                prefix += cur;
            }
        }

        return ans;
    }
};

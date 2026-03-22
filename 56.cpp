class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if ( intervals.empty() ) return ans;
        // Step 1: 先依照起點排序
        sort(intervals.begin(), intervals.end());

        // Step 2: 先把第一個區間當作目前合併中的區間
        vector<int> last = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& cur = intervals[i];

            // 如果重疊：更新目前區間的尾巴
            if (last[1] >= cur[0]) {
                last[1] = max(last[1], cur[1]);
            }
            // 如果不重疊：代表 last 已經結束，放進答案
            else {
                ans.push_back(last);
                last = cur;
            }
        }

        // Step 3: 最後一段別忘了放進答案
        ans.push_back(last);


        return ans;;
    }
};
//模板
sort(intervals.begin(), intervals.end());

current = intervals[0];

for (下一個區間) {
    if (重疊) {
        合併
    } else {
        push current
        current = 下一個區間
    }
}

push 最後一個 current

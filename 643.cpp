//固定窗口
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;

        // 先算第一個 window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double maxSum = sum;

        // sliding window
        for (int right = k; right < n; right++) {
            sum += nums[right];         // 加右邊
            sum -= nums[right - k];     // 減左邊
            maxSum = max(maxSum, sum);
        }

        return maxSum / k;
    }
};

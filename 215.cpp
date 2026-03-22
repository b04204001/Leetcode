class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        // 假設目前 i 是最大值位置
        int largest = i;

        // 左右子節點
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // 找出 i、left、right 三者中最大的
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        // 如果最大值不是原本的 i，交換後繼續往下調整
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: 先把整個陣列建成 max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // Step 2: 把最大值取出 k-1 次
        for (int i = 0; i < k - 1; i++) {
            // 堆頂 nums[0] 一定是目前最大值
            // 把它交換到 heap 最尾端
            swap(nums[0], nums[n - 1 - i]);

            // 重新整理剩下的 heap
            heapify(nums, n - 1 - i, 0);
        }

        // Step 3: 此時堆頂就是第 k 大
        return nums[0];
    }
};

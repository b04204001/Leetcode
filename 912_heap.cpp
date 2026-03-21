class Solution {
public:
    // 剛剛寫好的向下沉澱魔法
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest]) largest = left;
        if (right < n && nums[right] > nums[largest]) largest = right;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    // 主戰場
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // 🌟 階段一：建立 Max-Heap
        // 從最後一個「非葉節點 (有小孩的爸爸)」開始，一路往上做 heapify
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // 🌟 階段二：不斷把最大值 (nums[0]) 丟到最後面，然後重新整理
        for (int i = n - 1; i > 0; i--) {
            // 把最大的根節點換到目前的最後面
            swap(nums[0], nums[i]);
            
            // 樹的長度變成 i (也就是剛剛排好的最後面那個數字被排除了)
            // 針對換上來的根節點 (0) 重新做一次沉澱
            heapify(nums, i, 0); 
        }

        return nums;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // C++ priority_queue 預設是 max heap
        // 這裡用自訂 comparator 讓 val 較小的節點優先出來（min heap）
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // 先把每條 linked list 的頭節點放進 pq
        // pq 中永遠維護「每條 list 目前的頭」
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        // dummy node 方便串接答案
        ListNode dummy(0);
        ListNode* cur = &dummy;

        // 每次取出目前最小的節點，接到答案尾端
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            cur->next = node;
            cur = cur->next;

            // 若該節點後面還有節點，
            // 代表這條 list 有新的「頭」可以加入候選集合
            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};

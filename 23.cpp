class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // c++ pq預設是max heap，所以要拿小的要做成Min heap， true ->代表優先權低，所以讓a > b 代表大的數字優先權低。
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // 小的優先
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // 初始化：把每個 list 的頭放進去
        for (auto node : lists) {
            if (node) pq.push(node);
        }
        //dummy
        ListNode dummy(0);
        ListNode* cur = &dummy;
        //每次拿座小的接上去，然後往下一個節點直到沒有
        //cur是接的，node是pq取出來的下一個。
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            cur->next = node;
            cur = cur->next;
            //把「剛剛取出那條 list 的下一個節點」丟回候選集合
            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};

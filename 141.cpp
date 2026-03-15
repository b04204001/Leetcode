/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 防呆：如果連起點都沒有，或是只有一個節點，絕對不可能有圈圈
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* prev = head;
        ListNode* curr = head;
        while(curr != nullptr && curr->next != nullptr){
            prev= prev->next;
            curr = curr->next->next;
            if(prev == curr) return true;
        }

        return false;
    }
};

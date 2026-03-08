/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
                    return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode *curr= &dummy;
        ListNode *begin = curr->next;
        ListNode *tail = nullptr;
        int count = -1;
        // 1. 計算長度，並記下當下尾巴
        while(curr != nullptr){
            tail = curr;
            curr = curr->next;
            count++;
        }
        // 2.找出頭尾做截斷
        curr = begin;
        k = k % count;
        if (k == 0) return head;
        while( count > k + 1){
            curr = curr->next;
            count--;
        }
        //到達截斷前一個
        dummy.next = curr->next;
        tail->next = begin;
        curr->next = nullptr;
        

        return dummy.next;
    }
};

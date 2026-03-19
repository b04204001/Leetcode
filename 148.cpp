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
    // 負責合併兩條已經排好的鐵鍊
    ListNode* merge(ListNode* l1, ListNode* l2) {
        // ... 用 dummy 節點來接，誰小就接誰 ...
        ListNode dummy(0);
        ListNode*curr = &dummy;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        // 誰還有剩，就整串掛上去
        if (l1 != nullptr) curr->next = l1;
        if (l2 != nullptr) curr->next = l2;

        return dummy.next;
    }

    // 主程式：負責切開，並呼叫遞迴
    ListNode* sortList(ListNode* head) {
        // 1. 煞車系統：如果沒節點或只有1個節點，直接 return head
        if (head == nullptr || head->next == nullptr) return head;
        // 2. 快慢指標找中點 (找完記得剪斷鐵鍊！)
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        // 3. 遞迴叫左右兩邊自己排好
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        // 4. 把排好的左右兩邊合併起來
        return merge(left, right);
    }
};

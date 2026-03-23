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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        //快慢指針 (左要長於右)
        while(fast->next != nullptr && fast->next->next !=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondhead = slow->next;
        slow->next = nullptr;
        //反轉
        ListNode* prev = nullptr;
        ListNode* cur = secondhead;
        while (cur != nullptr) {
            ListNode* nextTemp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextTemp;
        }
        secondhead = prev;

        fast = head;
        slow = secondhead;
        //merge
        while(slow !=nullptr && fast !=nullptr){
            // 保持 左接右
            ListNode *temp1 = fast->next;
            ListNode* temp2 = slow->next;
            fast->next = slow;
            slow->next = temp1;
            slow = temp2;
            fast = temp1;
        }
    }
};

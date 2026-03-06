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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //1.dummy
        ListNode dummy(0);
        dummy.next = head;
        ListNode *curr = &dummy;
        int count = 0;
        while(curr != nullptr){
            count++;
            curr = curr->next;
        }
        //2.到刪除前
        curr = &dummy;
        for (int i=1;i<(count-n);i++){
            curr = curr->next;
        }
        //3.刪除

        ListNode *next2 = curr->next->next; //接的目標
        curr->next = next2;
        return dummy.next;


    }
};

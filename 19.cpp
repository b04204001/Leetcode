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
        //2.先讓快指針到位
        ListNode *fast = curr;
        for ( int i=0;i<n+1;i++){
            fast = fast->next;
        }
        //3. 讓快的到終點，慢的就是要刪除的前一個
        while(fast != nullptr){
            fast = fast->next;
            curr = curr->next;
        }
        //4.刪除
        curr->next = curr->next->next;
        return dummy.next;


    }
};

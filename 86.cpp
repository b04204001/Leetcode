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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0); // < x
        ListNode dummy2(0); // >=x
        ListNode *curr = head;
        ListNode *curr1 = &dummy1;
        ListNode *curr2 = &dummy2;
        while(curr != nullptr){
            if(curr->val >= x){
                curr2->next = curr;
                curr = curr->next;
                curr2 = curr2->next;
            }
            else{
                curr1->next = curr;
                curr = curr->next;
                curr1 = curr1->next;
            }
        }
        ListNode *begin2 = &dummy2;
        begin2 = begin2->next;
        curr1->next = begin2;
        curr2->next = nullptr;
        return dummy1.next ;
    }
};

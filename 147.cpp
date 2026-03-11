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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* lastsort = head;
        ListNode* curr= head->next;
        while(curr != nullptr){
            if( curr->val > lastsort->val){
                lastsort = lastsort->next;
            }
            else{
                ListNode* prev = &dummy;
                while(prev->next->val <= curr->val){
                    prev = prev->next;
                }
                lastsort->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;            
            }
            curr = lastsort->next;
        }
        return dummy.next;
    }
};

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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next !=NULL){
            slow = slow->next;
            fast= fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr != NULL){
            ListNode*temp = curr->next;
            curr->next =prev;
            prev = curr;
            curr = temp;
        }

        ListNode* first = head;
        ListNode* second = prev;
        int max_sum = 0;
        while(first != NULL && second != NULL){
            max_sum = max(max_sum, first->val + second->val);
            first=first->next;
            second =second->next;
        }
        return max_sum;

    }
};



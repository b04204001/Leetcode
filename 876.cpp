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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        ListNode* ans = head;
        int count =0;
        while( temp != nullptr){
            temp = temp->next;
            count++;
        }
        for(int i=0;i<count/2;i++){
            ans = ans->next;
        }
        return ans;
    }
};

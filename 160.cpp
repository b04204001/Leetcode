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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA;
        ListNode* B = headB;
        while( A != B){
            A = (!A) ? headB : A->next;
            B = (!B) ? headA : B->next;
        }
        return B;

    }
};

'''
用A作為相遇前長度、B為相遇前長度、C為相遇後長度
透過奏到盡頭串接，使得最終都走A + B + C ，會剛好停在相遇點，
'''
    

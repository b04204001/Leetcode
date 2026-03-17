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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        //找中間:快慢指標，走完剛好慢在中間
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast= fast->next->next;
        }
        //反轉後半，slow最後停在後半的頭
        fast = slow;
        slow = nullptr;
        while(fast != nullptr){
            ListNode* temp = slow;
            slow = fast;
            fast = fast->next;
            slow->next = temp;
        }
        //對比兩半
        fast = head;
        while(slow!= nullptr && fast != nullptr){
            if(slow != nullptr ^ fast != nullptr) return false;
            if(slow->val != fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};

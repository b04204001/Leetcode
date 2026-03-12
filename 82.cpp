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
    ListNode* deleteDuplicates(ListNode* head) {
        //if (head == nullptr || head->next == nullptr) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev =  &dummy;
        ListNode *curr = prev->next;

        while(curr != nullptr&& curr->next != nullptr){
            //1. 有重複
            if ( curr->val == curr->next->val){
                int value = curr->val;
                while( curr != nullptr && curr->val == value){
                    curr = curr->next;
                }
                //出來curre下一個不同的
                prev->next = curr;
            }
            //2. 無重複
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};



ㄥ
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while(curr != nullptr){
            //把curr移到重複的最後一格
            while(curr->next != nullptr && curr->val == curr->next->val){
                curr = curr->next;
            }
            //無重複，直接prev往前移動，對其等下的curr往前
            if(prev->next == curr){
                prev = prev->next;
            }
            //有重複，把prev跟curr->next連接，這樣重複都被踢掉。
            else{
                prev->next = curr->next;
            }
            //curr往前下一格，有重複因為中間刪掉，所以她還在前一格
            curr = curr->next;
        }
        return dummy.next;
    }
};

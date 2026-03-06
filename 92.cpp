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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //1.左邊接一個
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev_left = &dummy;
        //2.走道left上
        for (int i=1;i<left;i++ ){
            prev_left = prev_left->next;
        }
        //3. 開始反轉
        int count = right - left + 1 ;
        ListNode *curr = prev_left->next;
        ListNode *tail = curr;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        for (int i=0;i<count;i++){
            next = curr->next;
            curr->next = prev;
            prev = curr ;
            curr = next;
        }
        //4. 接上頭尾
        tail->next = curr;
        prev_left->next = prev ;

        return dummy.next;
    }
};

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        
        while(curr != nullptr){
            //有刪除
            if(curr->val == val){
                // ✨ 1. 先用一個暫時的指標，抓住這個準備被殺掉的節點
                ListNode* temp = curr;
                
                // 2. 鐵軌重新接好，並把 curr 往下移動
                prev->next = curr->next;
                curr = prev->next;
                
                // ✨ 3. 物理超渡！把記憶體還給系統
                delete temp;
            }
            //沒刪除
            else{
                prev = prev->next;
                curr = curr->next;
            }

        }
        return dummy.next;
    }
};

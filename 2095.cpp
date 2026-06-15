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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = slow;
        while(fast!= NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return head;
    }
};

//最優解
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // 邊界條件：若只有一個節點，刪除後回傳 nullptr
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        // 核心技巧：讓 fast 先走兩步，slow 留在原點
        // 這樣可以讓 slow 永遠保持在「中間節點的前一個」
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        // 快慢指針前進
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 此時 slow 剛好是中間節點的前驅節點 (Predecessor)
        ListNode* toDelete = slow->next; // 記錄要被刪除的節點
        slow->next = slow->next->next;   // 跳過中間節點
        
        delete toDelete; // 在 C++ 中釋放記憶體，避免 Memory Leak
        
        return head;
    }
};

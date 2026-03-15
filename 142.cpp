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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
    return nullptr;
    }
};




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
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow = head;
        ListNode*fast = head;
        //確認cycle
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if((fast == nullptr || fast->next == nullptr) ) return nullptr;
        while(head != slow){
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};

'''
原理:
假設頭->環路口設為A，環路口到相遇點為B，相遇點再到環入口為C。
這樣我們第一階段證明有環時，使用龜兔法:
2 * 烏龜 = 兔子
2 * (A + B) = A + B + C + B
這樣削掉可以得到 A = C
再以此來尋找環入口，
一個從頭 一個從相遇點一起走，因為A = C，所以他們會同時再環入口相遇
    
'''

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL) return head;
    struct ListNode dummy;
    struct ListNode* tail = head;
    //1.計算總長，保留舊尾
    int length = 1;
    while(tail->next != NULL){
        tail= tail->next;
        length++;
    }
    //2.找到新尾，找到新頭
    k = k % length;
    if (k == 0) return head; // 如果旋轉後不變，直接回傳
    
    int target = length - k - 1;
    struct ListNode* cur = head;
    while(target > 0){
        cur = cur->next;
        target--;
    }
    dummy.next = cur->next;
    cur->next = NULL;
    //3.接上
    tail->next = head;
    return dummy.next;
}

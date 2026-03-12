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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
        {
			return list2;
		}
		if(list2 == NULL)
        {
			return list1;
		} 
		if(list1->val <= list2->val)
        {
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		}
		else
        {
			list2 -> next = mergeTwoLists(list1, list2->next);
			return list2;            
		}
	}
};	



//2刷自己寫的
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode dummy(0);
        ListNode* p = list1; //下一個被接
        ListNode* q = list2; //下一個被接
        ListNode* r = &dummy; //排好最後一格

        //處理開頭
        if(list1->val <= list2->val){
            dummy.next = list1;
            p = p->next;
        }
        else{
            dummy.next = list2;
            q = q->next;
        }
        r = r->next;
        //正式開始
        while(p != nullptr || q != nullptr){
            if(p != nullptr && q != nullptr ){
                if( p->val <= q->val ){
                    r->next = p;
                    p = p->next;
                }
                else if( q->val < p->val ){
                    r->next = q;
                    q=q->next;
                }
            }
            else{
                if(q == nullptr  ){
                    r->next = p;
                    p = p->next;
                }
                else{
                    r->next = q;
                    q = q->next;
                }
            }
            r = r->next;
        }
        return dummy.next;
    }
};

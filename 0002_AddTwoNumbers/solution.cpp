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
    //[Performance]
    //Cost 64 ms for 1562 testcases, beats 50%.
    //[Algorithm]
    //constructor in struct definition is useful.  
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode head = ListNode(0);
        ListNode *nld = new ListNode(0);
        head.next = nld;
        ListNode *s1, *s2;
        s1 = l1; 
        s2 = l2;
        int ad = 0;
        while(s1 != NULL || s2 != NULL || ad == 1){    
            if (s1 != NULL){
                nld->val += s1->val;
                s1 = s1->next;
            }
            if (s2 != NULL){
                nld->val += s2->val;
                s2 = s2->next;
            }
            nld->val += ad;
            if (nld->val > 9){
                nld->val = nld->val - 10;
                ad = 1;
            }else{
                ad = 0;
            }
            if (s1 != NULL || s2 != NULL || ad == 1){
                ListNode *nld1 = new ListNode(0);
                nld->next = nld1;
                nld = nld->next;
            }
                        
        }
        return head.next;
    }
};
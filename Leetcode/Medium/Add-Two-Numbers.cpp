// tc : O(max(m,n)) sc : O(max(m,n))
// space complexity bcoz we create new linkedlist
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy;
        int c = 0;
        
        while(l1!=NULL or l2!=NULL or c!=0){
            int d = c;
            if(l1!=NULL){
                d += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                d += l2->val;
                l2 = l2->next;
            }
            ptr->next = new ListNode(d%10);
            ptr = ptr->next;
            c = d/10;
        }
        return dummy->next;
    }
};
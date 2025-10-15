class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
    if(!head)return 0;
    ListNode*slow = head, *fast=head->next,*NewLastNode =0;
    int sum =0;
    while(fast){
        if(fast->val != 0){
            //increment sum
            sum += fast->val;
        }
        else{
            slow->val = sum;
            NewLastNode = slow;
            slow = slow->next;
            sum =0;
        }
        fast = fast->next;
    }
    ListNode* temp = slow;
    //just formed new List
    NewLastNode->next = 0;
    while(!temp){
        ListNode*nxt = temp->next;
        delete temp;
        temp = nxt;
    }  
    return head;
    }
};

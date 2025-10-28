//Remove Duplicates from Sorted List

//C++ Solution

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //if(head == 0|| head->next == 0)return 0;
        ListNode*curr = head;
        while(curr&&curr->next){
            if( curr->val == curr->next->val){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};

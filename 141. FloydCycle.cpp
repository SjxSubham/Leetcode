#include<iostream>
using namespace std;

// Here i am giving only Two Pointer Approach

bool hasCycle(ListNode *head) {
        if(!head || !head->next)return 0;
        ListNode *slow = head;
        ListNode *fast = head;
        while(slow != NULL && fast!= NULL){
            fast = fast->next;                                   //Time Complexity o(n)
            if(fast != NULL){                                    //Space Complexity o(1)
                fast = fast->next;
            }
            slow = slow->next;
            if(slow == fast){
                return 1;
            }
        }
        return 0;
        
    }


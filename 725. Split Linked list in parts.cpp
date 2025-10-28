//T.c - 0(n)

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Function to split the linked list
// in K groups
    // Stores the K groups
    vector<ListNode*> ans;
 
    // If head is NULL
    if (!head) {
 
        // Iterate until K is non-zero
        while (k--)
            ans.push_back(NULL);
    }
 
    // Stores the length of the
        int N = 0;
 
    // Stores the head node 
      ListNode* p = head;
 
    // Iterate over the linked list
    while (p) {
 
        // Update p
        p = p->next;
 
        // Update N
        N++;
    }
 
    int len = N / k;
    int rem = N % k;
 
    p = head;
 
    // Iterate over the linked list
    while (k > 0 && p) {
 
        // Stores the length
        // of the current group
        int x = len;
 
        // Stores the current node
        ListNode* curr_head = p;
 
        // Stores the previous node
        ListNode* last = p;
 
        // If rem is greater than 0
        if (rem > 0) {
 
            // Update p
            p = p->next;
 
            // Decrement rem by 1
            rem--;
        }
 
        // Iterate until x is non-zero
        while (x--) {
 
            // If the last is equal to p
            if (last == p)
                p = p->next;
 
            // Otherwise
            else {
 
                // Join the link between
                // last and the current
                // element
                last->next = p;
 
                // Update the last node
                last = p;
 
                // Update p node
                p = p->next;
            }
        }
 
        // Assign NULL to last->next
        last->next = NULL;
 
        // Push the current linked
        // list in ans
        ans.push_back(curr_head);
 
        // Decrement K
        k--;
    }
 
    // While K greater than 0
    while (k > 0) {
 
        // Update the value of ans
        ans.push_back(NULL);
 
        // Increment K
        k--;
    }
    return ans;
    }
};

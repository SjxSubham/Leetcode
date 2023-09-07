//T.c -O(n)
//s.C -O(1)

// function used to reverse a linked list
    ListNode* reverse(ListNode* head)
{
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

 ListNode* reverseBetween(ListNode* head, int left, int right) {
        // function used to reverse a linked list from position m to n
    if (left == right)
        return head;
  
    // revs and revend is start and end respectively of the
    // portion of the linked list which need to be reversed.
    // revs_prev is previous of starting position and
    // revend_next is next of end of list to be reversed.
    ListNode*revs = NULL, *revs_prev = NULL;
    ListNode*revend = NULL, *revend_next = NULL;
  
    // Find values of above pointers.
    int i = 1;
    ListNode* curr = head;
    while (curr && i <= right) {
        if (i < left)
            revs_prev = curr;
        if (i == left)
            revs = curr;
        if (i == right) {
            revend = curr;
            revend_next = curr->next;
        }
        curr = curr->next;
        i++;
    }
    revend->next = NULL;
    // Reverse linked list starting with revs.
    revend = reverse(revs);
    // If starting position was not head
    if (revs_prev)
        revs_prev->next = revend;
    // If starting position was head
    else
        head = revend;
    revs->next = revend_next;
    return head;
}
        
    
};

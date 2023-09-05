//T.C - O(n)
//S.C - O(n)


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*a = headA;
        ListNode*b = headB;
        while(a->next && b->next){
            if(a==b){
                return a;
            }
            a = a->next;
            b = b->next;
        }      
        //intersection hai hi nhi
        if(a->next ==0 && b->next ==0 && a!=b)return 0;
        if(a->next==0){
            //b is bigger
            //we nee to found how much bigger it is
            int blen=0;
            while(b->next){
                blen++;
                b = b->next;
            }
            while(blen--){
                headB = headB->next;
            }
        }
        else{
                int alen =0;
                while(a->next){
                    alen++;
                    a = a->next;
                }
                while(alen--){
                    headA = headA->next;
                }
            }
            while(headA != headB){
                headA = headA->next;
                headB = headB->next;
            }
            return headA;
        
    }
};

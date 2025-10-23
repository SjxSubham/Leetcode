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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=NULL;
        ListNode* head=NULL;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            int x=l1->val;
            int y=l2->val;
            int sum=x+y+carry;
            int v=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(v);
            if(ans==NULL){
                ans=newNode;
                head=ans;
            }
            else{
                   ans->next=newNode;
                   ans=ans->next;

            }
            l1=l1->next;
            l2=l2->next;
          
        }
        

         while(l1!=NULL){
            int x=l1->val;
            int sum=x+carry;
            int v=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(v);
            if(ans==NULL){
                ans=newNode;
                
               head=ans;
            }
            else{
                   ans->next=newNode;
                    ans=ans->next;
            }
            l1=l1->next;
          
        }
          while(l2!=NULL){
            int x=l2->val;
            int sum=x+carry;
            int v=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(v);
            if(ans==NULL){
                ans=newNode;
                head=ans;
            }
            else{
                   ans->next=newNode;
                    ans=ans->next;

            }
          l2=l2->next;
        }
        if(carry>0){
            ListNode* newNode=new ListNode(carry);
            ans->next=newNode;
        }
        return head;

    }
};
// Here is the solution of this question without using map 
// It's is much optimized  

solution in C++

class Solution {
public:
  Node* copyRandomList(Node* head) {
       if(!head) return 0;
       // step 1: clone a -> a'
       Node* it = head;
       while(it){
           Node*clonedNode = new Node(it->val);
           clonedNode->next = it->next;
           it->next = clonedNode;
           it = it->next->next;

       }
       //step 2: assign random links of A with the help of random pouinter
        it = head;
        while(it){
            Node*clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
        }
        //step 3: detatch A from A
        it = head;
        Node*clonedHead = it->next;
        while(it){
            Node*clonedNode = it->next;
            it->next = it->next->next;
            if(clonedNode->next){
                clonedNode->next = clonedNode->next->next;

            }
            it = it->next;
        }
        return clonedHead;
    }
};

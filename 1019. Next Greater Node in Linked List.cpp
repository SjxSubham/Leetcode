//C++ solution
//T.C - 0(n) 81ms
//S.C - o(n) 41.9mb
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ll;
        while(head){
            ll.push_back(head->val);
            head = head->next;
        }
        stack<int>st;
        // vector<int>ans(ll.size()); // init 0
        for(int i =0;i<ll.size();++i){
            while(!st.empty() && ll[i]> ll[st.top()]){
                // i th element is greater than ith element of previous index element
                int kids = st.top();
                st.pop();
                ll[kids]  = ll[i];
            }
            st.push(i);
        }
        while(!st.empty()){
            ll[st.top()]= 0;
            st.pop();
        }
        ll[ll.size()-1] = 0;
        return ll;
    }
};

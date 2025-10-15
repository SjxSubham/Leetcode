class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = {-1, -1}; // minDist & maxDist
        ListNode* prev = head;
        if(!prev)return ans;
        ListNode* curr = head->next;
        if(!curr)return ans;
        ListNode* nxt = head->next->next;
        if(!nxt)return ans;

        int firstCp = -1;
        int LastCp = -1;
        int minDis = INT_MAX;

        int i=1;
        while(nxt){
            bool isCp = ((curr->val > prev->val && curr->val > nxt->val ) ||
                        (curr->val < prev->val && curr->val < nxt->val))
                        ? true : false;

            if(isCp && firstCp == -1){
                firstCp = i;
                LastCp = i;
            }
            else if(isCp){
                minDis = min(minDis, i- LastCp);
                LastCp = i;
            }
            ++i;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;;

        }
        //only One Cp is found 
        if(LastCp == firstCp){
            return ans;
        }
        else{
            ans[0] = minDis;
            ans[1] = LastCp - firstCp;
        }
        return ans;
    }
};

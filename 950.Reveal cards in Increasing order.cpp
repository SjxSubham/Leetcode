class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int>res(deck.size(),0);
        sort(deck.begin(), deck.end());
        int i = 0, j=0, k=0;
        while(j<deck.size()){
            if(res[i%deck.size()]==0 && k==0){
                res[i%deck.size()]=deck[j++];
                k=1;
            }else if(res[i%deck.size()] && k==1){
                k=1;
            } else k=0;
            i++;
        }
        return res;
    }
};
//TC-O(NlogN)

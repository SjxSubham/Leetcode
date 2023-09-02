//T.C - o(n)
//S.C - o(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //petrol ki kitni kami hai yani Ghat ti
        int deficit =0;
        //petrol kitna bacha hua hai
        int balance =0;
        ///circuit kha se suru kre 
        int start =0;
        for(int i =0;i<gas.size();i++){
            balance += gas[i] - cost[i];
            if(balance < 0){
                deficit += balance; // yahi par galti hoti hai...deficit ko increment krna padega   // or deficit += abs(balance);
                start = i+1;
                balance =0;
            }
        }
        if(deficit + balance >=0){   // or if(balance >= deficit)
            return start;
        }
        else{
            return -1;
        }
    }
};



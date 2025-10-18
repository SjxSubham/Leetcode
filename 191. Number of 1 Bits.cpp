class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count =0;

        //****Approach 1****
        // while( n!= 0){
        //     count += (n%2); // Remainder Count... easy Binary count
        //     n >>=1;
        // }
        // return count;

        //*****Approach 2*****
        // while(n>0){
        //     n = (n&(n-1));                                                                                                          //  Bit Manipulation
        //     count++;
        // }
        // return count;

        //*****Approach 3*****
        while(n !=0){
            count += (n%2); //Remainder Count... easy Binary count
            n = n/2;
        }
        return count;
    }
};

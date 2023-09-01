/*Explanation
1. we are iterating till n;
	for every i, we have to count 1's bits in its binary form.
	0 --> 0
	1 --> 1
	2 --> 10
	3 --> 11
	4 --> 100
	5 --> 101
	
	Output: [0,1,1,2,1,2]
  */
class Solution {
public:
// T.C - o(nlog n)
    vector<int> countBits(int n) {
        vector<int>ans;
        //loop ko 0 se n tak chalayenge
        for(int i=0;i<=n;i++){
            // sum is initialized as zero
            int sum =0;
            int num =i;
            //while num not equals zero
            while(num != 0){
                //we have to count '1' s in binary representation of i, there fore % 2
                sum += num%2;
                num = num/2;
            }
            //add sum to ans vector
            ans.push_back(sum);
        }
        //return 
        return ans;
    }
};

/*Approach
NOTE-PLEASE READ APPROACH FIRST THEN SEE THE CODE. YOU WILL DEFINITELY UNDERSTAND THE CODE LINE BY LINE AFTER SEEING THE APPROACH.

Approach for this Problem:

1. Sort the input array
2. Initialize a set to store the unique triplets and an output vector to store the final result
3. Iterate through the array with a variable i, starting from index 0.
4. Initialize two pointers, j and k, with j starting at i+1 and k starting at the end of the array.
  In the while loop, check if the sum of nums[i], nums[j], and nums[k] is equal to 0. If it is, insert the triplet into the set and increment j and decrement k to move the pointers.
5. If the sum is less than 0, increment j. If the sum is greater than 0, decrement k.
6. After the while loop, iterate through the set and add each triplet to the output vector.
7. Return the output vector

Complexity
Time complexity: O(n^2)
Space complexity: o(n)
*/
 //step 1:
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        int target =0;
        //step 2:make a output vector
        vector<vector<int>>output;
        //step 3: iteration of outer loop
        for(int i=0;i<nums.size();i++){
            int j = i+1;
            int k = nums.size() - 1;
            
            while(j< k){
                int sum = nums[i] + nums[j] + nums[k];
                if( sum == target){
                    s.insert({nums[i] , nums[j], nums[k]}); // storing into set
                    j++;
                    k--;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    k--;
                }
            }   
        }
             for(auto triplets : s)
                output.push_back(triplets);
                return output;
        

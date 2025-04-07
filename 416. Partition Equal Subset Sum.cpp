public:
int t[201][20001];
    // before memo - O(2^n) : memo - O(n * x)
    //S.C : O(n*X)
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int S = accumulate(nums.begin(), nums.end(),0);

        if(S%2 != 0){
            return false;
        }
        memset(t, -1, sizeof(t));
        int x = S/2;

        return solve(nums, 0, x);
    }
    bool solve(vector<int>& nums, int i, int x){                         // All good also try to solve the GFG problem named as Subset Sum - https://www.geeksforgeeks.org/problems/subset-sums2234/1 solve here 
        if(x==0){
            return true;
        }

        if(i >= nums.size()){
            return false;
        }

        if(t[i][x] != -1){
            return t[i][x];
        }

        // vector<vector<int>> t(n+1, vector<int>(x+1))

        bool take = false;
        if(nums[i] <= x){
            take = solve(nums, i+1, x- nums[i]);
        }

        bool not_take = solve(nums, i+1, x);

        return t[i][x] = take|| not_take;
    }
};


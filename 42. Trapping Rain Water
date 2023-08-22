//Here is the two pointer approach
//by taking auxaliary space of O(n)

//Here I'm giving Both C++ & java Solution

// C++  Solution                                                             //and for java solution scroll down 

class Solution {
public:
    int trap(vector<int>&height) {
        //Space COmplexity O(n)
        //Time Complexity O(n)
        int n = height.size();

        vector<int>left(n);
        left[0] = height[0];

        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
        }

        vector<int>right(n);
        right[n-1] = height[n-1];

        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],height[i]);
        }
        
        int ans =0;
        for(int i=0;i<n;i++){
            ans += (min(right[i],left[i])-height[i]);
        }
        return ans;
    
    }
};

// Java Solution

class Solution {
    public int trap(int[] height) {
        //SPace Complexitiy O(n)
        int n = height.length;
        int left[] = new int[n];
        int right[] = new int[n];
        left[0] = height[0];
        for(int i=1;i<n;i++){
            left[i] = Math.max(left[i-1],height[i]);
        }
        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = Math.max(right[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            //formula
            ans += (Math.min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};



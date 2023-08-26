//here we have to learn two more quentions first ...
//Which are most important in Stack
// 1.next Smaller Element
//2. prev Smaller Element

//then we will be able to solve it
//Formula----
// area = length * width;


class Solution {
public:
    vector<int>nextSmallerElement(vector<int>& input){
        stack<int>s;
        s.push(-1);
        vector<int>ans(input.size());
        for(int i=input.size()-1;i>=0;i--){
            int curr = input[i];
            while(s.top()!= -1 && input[s.top()] >= curr){
                s.pop();
            }
            //chota mil chuka hai store ans
            ans[i] = s.top();
            //push kardo element ko
            s.push(i);
        }
        return ans;
    }
    vector<int>prevSmallerElement(vector<int>& input){
        stack<int>s;
        s.push(-1);
        vector<int>ans(input.size());
        //left to right
        for(int i=0;i<input.size();i++){
            int curr = input[i];
        
        while(s.top()!= -1 && input[s.top()] >= curr){
            s.pop();
        }
        //chota element mil chuka hai
        ans[i] = s.top();
        //push kardo elment ko
        s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        //prev smaller call
       vector<int>prev =  prevSmallerElement(heights);
       //next smaller call
       vector<int>next =  nextSmallerElement(heights);
        int MaxArea = INT_MIN;
        int size = heights.size();

        for(int i=0;i<heights.size();i++){
            int length = heights[i];

            if(next[i] == -1){
                next[i] = size;
            }
            int width = next[i] - prev[i] -1;
            int area = length * width;
            MaxArea = max(MaxArea,area);
        }
        return MaxArea;
    }
};

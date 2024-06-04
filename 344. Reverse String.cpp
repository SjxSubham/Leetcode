  // using vector
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};

// using iteration
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0;
        int r = s.size()-1;
        while(l<=r){
            swap(s[l++],s[r--]);
        }
    }
};

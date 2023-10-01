//T.C - O(n)
//S.C - O(1)

public:
    string reverseWords(string s) {
       int i=0;
       for(int j=0;j<s.size();j++) {
           if(s[j] == ' '){
               reverse(s.begin() +i,s.begin() +j);
               i = j+1;
           }
       }
       reverse(s.begin() +i,s.end());
       return s;
    }

So, here also let's say our character are:
s = abc
t = cabx

if we take XOR of every character. all the n character of s "abc" is similar to n character of t "cab". So, they will cancel each other. 
And we left with our answer.

s =   abc
t =   cbax
------------
ans -> x

char findTheDifference(string s, string t) {
      char c = 0;
      for(char cs : s) c^=cs;       //Xoring all charecter to extract unique one 
      for(char ct : t) c^=ct;
      return c;
    } 

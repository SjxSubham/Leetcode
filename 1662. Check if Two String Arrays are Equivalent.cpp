// Use any of two approaches below

T.c - O(n)
s.c - O(1)
  
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

    // Approach 1
     string s1 = "";
        string s2 = ""; 
        for(string s: word1){
        s1.append(s);
        }
        for(string p: word2){
        s2.append(p);
        }
        if(s1 == s2){
            return true;
        }
        return false;

  
    //Approach 2
    // Nice Approach                                                                                    // Use any of two approaches
  
       int m = word1.size();
       int n = word2.size();

       int w1i=0; int i =0;
       int w2i =0; int j =0;

       while(w1i < m && w2i < n){
           if(word1[w1i][i] != word2[w2i][j])
            return false;
        i++;
        j++;
        if(i ==word1[w1i].length()){
            i =0;
            w1i++;
        }
        if(j == word2[w2i].length()){
            j =0;
            w2i++;
            }
       }
       if(w1i == word1.size() && w2i == word2.size())
            return true;

       return false;
    }

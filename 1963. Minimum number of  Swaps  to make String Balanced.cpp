// ************************************* C++ *************************************

T.C - O(n)

  
    int minSwaps(string s) {
        int size = 0;
        
        for(char &ch : s) {
            if(ch == '[')      
              size++;
            else if(size != 0)
              size--;
        }
        
        return (size+1)/2;
    }
};

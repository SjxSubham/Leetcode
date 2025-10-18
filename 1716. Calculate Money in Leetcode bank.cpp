



class Solution {
public:

  // Approach 1
                                    //T.c - O(n)

    int totalMoney(int n) {
       int total = 0;
       int monday =1;
       while(n>0){
           int money = monday;
           for(int day=1; day<=min(n,7); day++){
               total += money; //1
               money++; //2,3
           }
           n -= 7;
           monday++;
       }
       return total;

  // Approach 2
                              // T.C - O(1)
      //math Approach A.P series
      int terms = n/7;
    int first = 28;
    int last = 28 +(terms -1)*7; // A.P formula
    int result = terms *(first + last)/2; // sum of nth term in A.P

    //first week remaining days
    int start_money = 1+ terms;
    for( int day = 1; day <=(n%7); day++){
        result += start_money;
        start_money++;
    }
      return result;
    }
}

    return result;
      
    }
};

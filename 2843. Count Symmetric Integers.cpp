  int countSymmetricIntegers(int low, int high) {
        //brute Force
        int count =0;
        for(int num=low; num<= high; num++){
            string s = to_string(num);

            int l = s.length();

            if(l%2 !=0){
                continue;
            }
            int leftsum = 0;
            int rightsum=0;
            for(int i=0; i<l/2; i++){
                leftsum += s[i] - '0';
            }
            for(int i=l/2; i<l; i++){
                rightsum += s[i] -'0';
            }
            if(leftsum == rightsum){
                count++;
            }
        }
        return count;
    }

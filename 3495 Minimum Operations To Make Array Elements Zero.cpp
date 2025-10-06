class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        for(int i=0;i<queries.size();i++){
            long long log4a=1;
            long long a=queries[i][0];
            long long b=queries[i][1];
            long long log4b=1;
            while(a>3){
                log4a++;
                a/=4;
            }
            while(b>3){
                log4b++;
                b/=4;
            }
            if(log4a==log4b){
                ans+=((queries[i][1]-queries[i][0]+1)*log4a+1)/2;
                continue;
            }
            long long st=pow(4,log4a);
            long long end=pow(4,(log4b-1));
            long long sum=(st-queries[i][0])*log4a;
            sum+=(queries[i][1]-end+1)*log4b;
            log4a++;
            while(log4a<log4b){
                long long temp=st*4;
                sum+=(temp-st)*log4a;
                st=temp;
                log4a++;
            }
            ans+=(sum+1)/2;
        }
        return ans;
    }
};
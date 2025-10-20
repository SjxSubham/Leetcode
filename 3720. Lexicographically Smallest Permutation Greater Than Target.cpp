#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string ans ="";
        int n = s.length();
        map<char,int>mp;
        for(auto&e:s)mp[e]++;
        for(int i =0;i<n;i++)
            {
                map<char,int> m2=mp;
                string res ="";
                bool ip=1;
                for(int j = 0;j<i;j++)
                    {
                        char e=target[j];
                        if(!m2.count(e))
                        {
                            ip=0;
                            break;
                        }
                        res+=e;
                        m2[e]--;
                        if(m2[e]==0)m2.erase(e);
                    }
                if(ip)
                {
                            char e = target[i];
                            auto it = m2.upper_bound(e);
                            if(it!=m2.end())
                            {
                                res+=it->first;
                                it->second--;
                                if(it->second==0)m2.erase(it);
                            }
                    else continue;
                    for(auto&e:m2)
                        {
                            while(e.second--)res+=e.first;
                        }
                    if(ans =="")ans=res;
                    else ans = min(ans,res);
                }
            }
        return ans;
    }
};
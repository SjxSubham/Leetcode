class Solution {
public:
    vector<string> ans;

  map<char,string> mp;
    void help(string digits,int id,string& str)
    {
        if(id>digits.size()) return;
        if(id>=digits.size()) 
        {   ans.push_back(str);
            return;
        }
        
        string st=mp[digits[id]];
        for(int i=0;i<st.size();i++)
        {
            str=str+st[i];
            help(digits,id+1,str);
            str.pop_back();
            // help(digits,id+1,str);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
      
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string str;
        help(digits,0,str);
        return ans;

    }
};

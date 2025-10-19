class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        if (words.size() == 1)
            return {words[0]};
        vector<string> ans;
        ans.push_back(words[0]);
        for (int i = 1; i < words.size(); i++)
        {
            string tempcurr = words[i];
            string prevtemp = words[i - 1];
            sort(tempcurr.begin(), tempcurr.end());
            sort(prevtemp.begin(), prevtemp.end());
            if (tempcurr != prevtemp)
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
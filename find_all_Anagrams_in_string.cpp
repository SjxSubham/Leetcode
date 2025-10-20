#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> arr(26, 0);
        
        int m = s.length();
        int n = p.length();

        if (n == 0) {
            // For empty pattern, return all possible indices (including s.length())
            vector<int> result;
            for (int i = 0; i <= m; ++i) {
                result.push_back(i);
            }
            return result;
        }
        if (n > m) return {};

        for (char &ch : p)
            arr[ch - 'a']++;
        
        int i = 0, j = 0;
        vector<int> result;
        
        while (j < m) 
        {
            arr[s[j] - 'a']--;
            
            if (j - i + 1 == n) 
            {
                if (arr == vector<int>(26, 0))
                    result.push_back(i);
                
                arr[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        
        return result;
    }
};

int main() 
{
    Solution sol;
    string s, p;
    
    cout << "Enter string s: ";
    cin >> s;
    
    cout << "Enter pattern p: ";
    cin >> p;
    
    vector<int> res = sol.findAnagrams(s, p);
    
    cout << "Output indices: [";
    for (int i = 0; i < res.size(); i++) 
    {
        cout << res[i];
        if (i != res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}

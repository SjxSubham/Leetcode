class Solution {
public:
    string removeSubstring(string s, int k) {
        stack<pair<char, int>> stk;
        auto f = [&]() -> void {
            int cnt = 0;
            int len = 0;
            for(auto &I : s) {
                if(I == '(' && !stk.empty() && stk.top().first == I) {
                    stk.top().second++;
                } else if(I == '(') {
                    stk.push({I, 1});
                    len++;
                }
                if(I == ')' && !stk.empty() && stk.top().first == I) {
                    stk.top().second++;
                } else if(I == ')') {
                    stk.push({I, 1});
                    len++;
                }
                //cout << len << endl;
                if(len >= 2) {
                    // atleast one ( and one ) present
                    if(stk.top().first == ')' && stk.top().second >= k) {
                        // enough ')' there
                        // stk = ((()))())(()) , and if k = 2 
                        auto preserve_top = stk.top();
                        stk.pop();
                        if(stk.top().first == '(' && stk.top().second >= k){
                            int viable = min(preserve_top.second, stk.top().second);
                            stk.top().second -= viable;
                            preserve_top.second -= viable;
                            if(stk.top().second == 0) {
                                stk.pop();
                                len--;
                            }
                            if(preserve_top.second == 0) {
                                len--;
                            } else {
                                stk.push(preserve_top);
                            }
                        } else {
                            stk.push(preserve_top);
                        }
                    }
                }
            }
            if(!stk.empty() && stk.top().second == 0) {
                stk.pop();
            }
        };
        f();
        string ans;
        while(!stk.empty()) {
            int times = stk.top().second;
            while(times--)
                ans.push_back(stk.top().first);
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
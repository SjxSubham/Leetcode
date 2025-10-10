#include <bits/stdc++.h>
using namespace std;

class ValidNumber {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;

        // Remove leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // Remove trailing whitespaces
        int j = n - 1;
        while (j >= 0 && s[j] == ' ') j--;

        if (i > j) return false;

        bool num = false;   // At least one digit before e
        bool dot = false;   // Only one '.'
        bool exp = false;   // Only one 'e' or 'E'

        for (int k = i; k <= j; k++) {
            char c = s[k];

            if (isdigit(c)) {
                num = true;
            } 
            else if (c == '.') {
                // Only one '.' and it can't appear after e
                if (dot || exp) return false;
                dot = true;
            } 
            else if (c == 'e' || c == 'E') {
                // e must appear only once and must follow a number
                if (exp || !num) return false;
                exp = true;
                num = false; // Reset, we need digits after e
            } 
            else if (c == '+' || c == '-') {
                // Sign must be at start or immediately after e
                if (k != i && s[k-1] != 'e' && s[k-1] != 'E')
                    return false;
            } 
            else {
                return false;
            }
        }

        return num;
    }
};


//  Time Complexcity - O(n)

string decodeAtIndex(string s, int k) {
        
        long long length = 0;
        int i = 0;
        
        while (length < k) {
            if (isdigit(s[i])) {
                length *= s[i] - '0';
            } else {
                length++;
            }
            i++;
        }
        
        for (int j = i - 1; j >= 0; j--) {
            if (isdigit(s[j])) {
                length /= s[j] - '0';
                k %= length;
            } else {
                if (k == 0 || k == length) {
                    return string(1, s[j]);  // Convert char to std::string
                }
                length--;
            }
        }
        
        return  s;
    }

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n, 0), right(n, 0);

        // Step 1: Propagate rightward forces
        int force = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') force = n;          // reset strong rightward force
            else if (dominoes[i] == 'L') force = 0;     // leftward push blocks rightward
            else force = max(force - 1, 0);             // decrease over distance
            right[i] = force;
        }

        // Step 2: Propagate leftward forces
        force = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') force = n;          // reset strong leftward force
            else if (dominoes[i] == 'R') force = 0;     // rightward push blocks leftward
            else force = max(force - 1, 0);             // decrease over distance
            left[i] = force;
        }

        // Step 3: Determine final state
        string result;
        for (int i = 0; i < n; i++) {
            if (left[i] == right[i]) result += '.';
            else if (left[i] > right[i]) result += 'L';
            else result += 'R';
        }

        return result;
    }
};

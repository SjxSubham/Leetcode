class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        int n = fruits.size();
        int m = baskets.size();

    for (int i = 0; i < n; i++) {
        bool placed = false;
        for (int j = 0; j < m; j++) {
            if (baskets[j] >= fruits[i]) {
                baskets[j] = -1; 
                placed = true;
                break;
            }
        }

        if (!placed) {
            unplaced++;
        }
    }

    return unplaced;
    }
};
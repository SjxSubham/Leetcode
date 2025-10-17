
class Solution {
    public int minDominoRotations(int[] t, int[] bo) {
        int[] a = new int[7];
        int[] b = new int[7];
        for (int p : t) a[p]++;
        for (int p : bo) b[p]++;
        int max1 = 0, maxval1 = 0;
        for (int i = 1; i <= 6; i++) {
            if (a[i] > max1) {
                max1 = a[i];
                maxval1 = i;
            }
        }
        int max2 = 0, maxval2 = 0;
        for (int i = 1; i <= 6; i++) {
            if (b[i] > max2) {
                max2 = b[i];
                maxval2 = i;
            }
        }
        int c1 = 0, c2 = 0;
        for (int i = 0; i < t.length; i++) {
            if (t[i] == bo[i]) {
                if (t[i] == maxval1) {
                    max1--;
                    b[maxval1]--;
                    c1++;
                } if (t[i] == maxval2) {
                    max2--;
                    a[maxval2]--;
                    c2++;
                }
            }
        }
        int n = t.length;
        int max1b = b[maxval1];
        int max2a = a[maxval2];
        if (max1b + max1 == n - c1 || max2a + max2 == n - c2) {
            return Math.min(n - c1 - Math.max(max1, max1b),
                            n - c2 - Math.max(max2, max2a));
        }

        return -1;
    }
}

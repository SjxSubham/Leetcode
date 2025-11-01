#include <iostream>
using namespace std;
/*
APPROACH:
Use an array to track lengths of increasing streaks, then apply binary search
to find the largest k for which two adjacent increasing subarrays exist.
*/
bool check(int *inc, int n, int k)
{
    for (int end1 = k - 1; end1 + k < n; end1++)
    {
        if (inc[end1] >= k && inc[end1 + k] >= k)
        {
            return true;
        }
    }
    return false;
}

int maxIncreasingSubarrays(int *nums, int numsSize)
{
    int n = numsSize;
    int inc[n];
    for (int i = 0; i < n; i++)
        inc[i] = 1;

    // Build the increasing streak lengths
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            inc[i] = inc[i - 1] + 1;
        }
    }

    int L = 1, R = n / 2;
    int ans = 0;

    // Binary search for max k
    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        if (check(inc, n, mid))
        {
            ans = mid; // mid works, try bigger k
            L = mid + 1;
        }
        else
        {
            R = mid - 1; // mid too big, try smaller k
        }
    }

    return ans;
}

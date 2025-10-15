```cpp
// Problem: 3362. Zero Array Transformation III

// Approach:
// Intuition:
// The problem asks us to transform an array of non-negative integers into an array of all zeros using a specific operation. The operation involves choosing an index `i` and a non-negative integer `x`, then subtracting `x` from `nums[i]` and `nums[i+1]`. We want to find the minimum total sum of `x` values used.

// Let's analyze the operation. When we subtract `x` from `nums[i]` and `nums[i+1]`, it means `nums[i]` and `nums[i+1]` are reduced by the same amount. This suggests a greedy approach from left to right.

// Consider `nums[0]`. To make `nums[0]` zero, we must apply an operation at index `0` with `x = nums[0]`. This will also affect `nums[1]`. After this operation, `nums[0]` becomes zero. We then move to `nums[1]` (which has been modified) and repeat the process.

// Let `dp[i]` be the minimum operations to make `nums[0...i]` zero. This seems complicated because an operation at `i` affects `i+1`.

// Let's try a direct greedy approach. Iterate from `i = 0` to `n-1`.
// For each `nums[i]`, if `nums[i]` is not zero, we must perform an operation at index `i` to make it zero. The value of `x` for this operation must be `nums[i]` itself. This operation will also subtract `nums[i]` from `nums[i+1]` (if `i+1 < n`).
// We add `nums[i]` to our total operations count.

// Example:
// nums = [1, 2, 3]

// i = 0: nums[0] = 1. We need to subtract 1 from nums[0] and nums[1].
// x = 1. Total operations = 1.
// nums becomes [0, 1, 3]

// i = 1: nums[1] = 1. We need to subtract 1 from nums[1] and nums[2].
// x = 1. Total operations = 1 + 1 = 2.
// nums becomes [0, 0, 2]

// i = 2: nums[2] = 2. We need to subtract 2 from nums[2] (and nums[3] if it existed, but it doesn't).
// x = 2. Total operations = 2 + 2 = 4.
// nums becomes [0, 0, 0]

// This greedy strategy seems to work. For each element `nums[i]`, if it's positive, we must reduce it to zero. The only way to reduce `nums[i]` without affecting `nums[0...i-1]` (which we've already made zero) is to apply the operation at index `i`. The amount we subtract, `x`, must be exactly `nums[i]` to make it zero. This `x` then also reduces `nums[i+1]`.

// Solution in Code:
class Solution {
public:
    long long zeroArray(vector<int>& nums) {
        long long total_operations = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                total_operations += nums[i];
                if (i + 1 < n) {
                    nums[i+1] -= nums[i];
                }
                nums[i] = 0; // nums[i] is now zero
            }
        }
        return total_operations;
    }
};
```
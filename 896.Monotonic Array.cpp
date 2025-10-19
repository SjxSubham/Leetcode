      // T.C - O(n)
      // S.C - O(1)


bool isMonotonic(vector<int>& nums) {
         bool isIncreasing = true, isDecreasing = true;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] < nums[i - 1]) {
      isIncreasing = false;
    }
    if (nums[i] > nums[i - 1]) {
      isDecreasing = false;
    }
  }

  // Return true if the array is increasing or decreasing
  return isIncreasing || isDecreasing;

    }

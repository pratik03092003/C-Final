#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The helper function's signature now includes the memoization table
vector<int> solve(const vector<int>& nums, int index, vector<vector<int>>& memo);

// Main function to find the Largest Divisible Subset
vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.size() <= 1) {
        return nums;
    }

    sort(nums.begin(), nums.end());

    // --- NEW: Create and initialize the memoization table ---
    // We initialize it with a sentinel value: a vector containing just -1.
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(1, -1));

    vector<int> overallBestSubset;

    for (int i = 0; i < n; ++i) {
        // --- MODIFIED: Pass the memo table to the helper function ---
        vector<int> currentSubset = solve(nums, i, memo);
        if (currentSubset.size() > overallBestSubset.size()) {
            overallBestSubset = currentSubset;
        }
    }

    return overallBestSubset;
}

/**
 * @brief Memoized recursive helper function.
 * Finds the largest divisible subset that MUST end at the given index.
 */
vector<int> solve(const vector<int>& nums, int index, vector<vector<int>>& memo) {
    // --- NEW: Step 1 - Check the cache first ---
    // If the entry is not our sentinel value, we've been here before. Return the stored result.
    if (memo[index][0] != -1) {
        return memo[index];
    }

    // --- The logic below is the same as before ---
    vector<int> longestPreviousSubset;
    for (int j = 0; j < index; ++j) {
        if (nums[index] % nums[j] == 0) {
            // --- MODIFIED: Pass the memo table in the recursive call ---
            vector<int> previousSubset = solve(nums, j, memo);

            if (previousSubset.size() > longestPreviousSubset.size()) {
                longestPreviousSubset = previousSubset;
            }
        }
    }

    longestPreviousSubset.push_back(nums[index]);

    // --- NEW: Step 2 - Store the result in the cache before returning ---
    memo[index] = longestPreviousSubset;
    return memo[index];
}


int main() {
    // Now this will run fast even with larger inputs.
    vector<int> nums = {5, 9, 18, 54, 108, 540, 90, 180, 360, 720};

    cout << "Finding the Largest Divisible Subset..." << endl;
    vector<int> result = largestDivisibleSubset(nums);

    cout << "The result is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Expected: 5 90 180 360 720 (or another valid subset of the same size)

    return 0;
}
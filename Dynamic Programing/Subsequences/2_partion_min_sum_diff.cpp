#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n) {
    // Calculate the total sum of the array
    int totSum = 0;
    for(int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // dp[i][j] = is it possible to get sum j using first i elements
    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

    // Base Case 1: A sum of 0 is always possible
    for(int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base Case 2: With the first element, only its value is a possible sum
    if(arr[0] <= totSum) {
        dp[0][arr[0]] = true;
    }

    // Fill the DP table
    for(int ind = 1; ind < n; ind++) {
        for(int target = 1; target <= totSum; target++) {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if(arr[ind] <= target) {
                take = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = take || notTake;
        }
    }

    // --- This is the part that was cut off ---
    // Iterate through the last row of the dp table to find the minimum difference
    int mini = 1e9; // A large number

    // We only need to check up to totSum / 2.
    // For every possible sum s1, the other sum s2 is (totSum - s1).
    // The difference is abs(s2 - s1) = abs(totSum - 2*s1).
    for(int s1 = 0; s1 <= totSum / 2; s1++) {
        // If a sum of s1 is possible...
        if(dp[n - 1][s1] == true) {
            mini = min(mini, abs(totSum - 2 * s1));
        }
    }
    return mini;
}

int main() {
    vector<int> arr = {1, 2, 7};
    int n = arr.size();
    cout << "The minimum subset sum difference is: " << minSubsetSumDifference(arr, n) << endl;
    return 0;
}
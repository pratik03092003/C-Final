#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base cases
        if (target == 0) return true;             // empty subset = true
        if (i == 0) return arr[0] == target;      // only one element left

        if (dp[i][target] != -1) return dp[i][target];

        // Not take current element
        bool notTake = f(i - 1, target, arr, dp);

        // Take current element (if <= target)
        bool take = false;
        if (arr[i] <= target)
            take = f(i - 1, target - arr[i], arr, dp);

        return dp[i][target] = (take || notTake);
    }

    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(n - 1, k, arr, dp);
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> arr = {1, 2, 3, 7};
    int target = 6;
    int n = arr.size();

    if (sol.subsetSumToK(n, target, arr))
        cout << "YES, a subset with sum " << target << " exists.\n";
    else
        cout << "NO, subset with sum " << target << " does not exist.\n";

    return 0;
}

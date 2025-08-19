#include<bits/stdc++.h>
using namespace std;
int solve( vector<int>& nums, int i, vector<int>& dp) {
    if(i==0) return 1;
    if(dp[i]!=-1) return dp[i];
    int max_len= 1;
    for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
            // Recur for the subproblem and add 1 if nums[i] can extend it.
            max_len= max(max_len , 1 + solve(nums, j, dp));
        }
        
        
    }
  return dp[i]= max_len;;
}

int lengthOfLIS( vector<int>& nums){
    if(nums.size()==0) return 0;
    int n = nums.size();
    vector<int> dp(n,-1);
    int max_lis =0;
    for (int i = 0; i < n; ++i) {
        max_lis = max(max_lis, solve(nums, i, dp));
    }

    return max_lis;

}

int main(){
    vector<int> my_sequence = {10, 9, 2, 5, 6, 7, 101, 18};
    cout << "The length of the LIS is: " << lengthOfLIS(my_sequence) << endl; // Output: 4

    return 0;
}
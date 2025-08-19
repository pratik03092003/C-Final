#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int findKthSmallest(vector<int>& nums, int k) {
   priority_queue<int> pq;
   for(auto i : nums){
    pq.push(i);
    if(pq.size()>k){
        pq.pop();
    }
   }
   return pq.top();
}



int main() {
    vector<int> arr = {10, 20, -4, 6, 18, 24, 105, 118};
    int k = 4; 
    cout << "The " << k << "rd smallest element is: " << findKthSmallest(arr, k) << endl;
    // Expected output: 6
    return 0;
}
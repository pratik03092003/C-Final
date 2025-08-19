#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> sortKSortedArray(vector<int>& nums, int k) {
    vector<int> result;
    // Min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        // Once we have more than k elements, the smallest one can be finalized
        if (minHeap.size() > k) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
    }

    // Add remaining elements from the heap to the result
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}

int main() {
    vector<int> arr = {6, 5, 2, 3, 8, 10, 9}; 
    int k = 3; 
    vector<int> sortedArr = sortKSortedArray(arr, k);
    cout << "Sorted array: ";
    for (int val : sortedArr) {
        cout << val << " ";
    }
    cout << endl;
    // Expected output: 2 3 5 6 8 9 10 
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // 1. Count frequencies
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    // 2. Use a min heap (store {frequency, element})
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> minHeap;

    for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
        int element = it->first;
        int freq = it->second;
        minHeap.push({freq, element});

        if ((int)minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // 3. Extract elements from the heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}

int main() {
    vector<int> arr = {1, 1, 1, 3, 3, 2};
    int k = 2;

    vector<int> result = topKFrequent(arr, k);

    cout << "Top " << k << " frequent elements are: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Expected output: 1 3 (order may vary)
    return 0;
}

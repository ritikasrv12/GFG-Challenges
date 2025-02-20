#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> medians;
        priority_queue<int> maxHeap; // Max heap for left half
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for right half

        for (int num : arr) {
            // Step 1: Insert into appropriate heap
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            // Step 2: Balance the heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // Step 3: Calculate median
            if (maxHeap.size() == minHeap.size()) {
                medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                medians.push_back(maxHeap.top());
            }
        }
        return medians;
    }
};

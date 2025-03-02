class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result;
        deque<int> dq; // Stores indices of array elements

        for (int i = 0; i < arr.size(); i++) {
            // Remove elements that are out of the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove elements from the back if they are smaller than the current element
            while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();

            // Add the current index to deque
            dq.push_back(i);

            // Store the maximum element of the current window
            if (i >= k - 1)
                result.push_back(arr[dq.front()]);
        }

        return result;
    }
};

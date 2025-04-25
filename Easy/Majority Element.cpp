class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int count = 0;
        int candidate = -1;

        // Step 1: Find the candidate
        for (int num : arr) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Step 2: Verify the candidate
        count = 0;
        for (int num : arr) {
            if (num == candidate) {
                count++;
            }
        }

        return (count > arr.size() / 2) ? candidate : -1;
    }
};

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
         // If the array has less than 2 elements, return an empty vector
        if (arr.size() < 2) return {};

        // Sort the array to use the two-pointer technique
        sort(arr.begin(), arr.end());

        int closestSum = INT_MAX;
        int maxAbsDiff = INT_MIN;
        vector<int> result;

        int left = 0, right = arr.size() - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            // Calculate the absolute difference between the target and current sum
            int diff = abs(target - sum);

            if (diff < abs(target - closestSum) || 
               (diff == abs(target - closestSum) && abs(arr[right] - arr[left]) > maxAbsDiff)) {
                // Update the closest sum and result pair
                closestSum = sum;
                maxAbsDiff = abs(arr[right] - arr[left]);
                result = {arr[left], arr[right]};
            }

            // Adjust pointers based on the sum compared to the target
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return result;
        // code here
    }
};

class Solution {
public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1; // since one number is missing
        int totalSum = n * (n + 1) / 2;

        int currentSum = 0;
        for (int num : arr) {
            currentSum += num;
        }

        return totalSum - currentSum;
    }
};

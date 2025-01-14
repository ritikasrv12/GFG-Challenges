class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        for (long long sum = accumulate(arr.begin(), arr.end(), 0LL), sum2 = 0, i = 0; i < arr.size(); sum2 += arr[i++])
            if ((sum -= arr[i]) == sum2) return i;
        return -1;
        // code here
    }
};

class Solution {
public:
    int maxLength(string& str) {
        int left = 0, right = 0, maxi = 0;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(')
                left++;
            else
                right++;

            if (left == right)
                maxi = max(maxi, 2 * right);
            else if (right > left)
                left = right = 0;
        }
        left = right = 0;
        for (int i = str.size() - 1; i >= 0; i--) {
            if (str[i] == '(')
                left++;
            else
                right++;

            if (left == right)
                maxi = max(maxi, 2 * left);
            else if (left > right)
                left = right = 0;
        }

        return maxi;
    }
};

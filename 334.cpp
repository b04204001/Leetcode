class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX, mid = min;

        for (int i : nums) {
            if (i < min) {
                min = i;
            } else if (i > min && i < mid) {
                mid = i;
            } else if (i > mid) {
                return true;
            }
        }
        return false;
    }
};

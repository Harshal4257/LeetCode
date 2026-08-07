class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int low = 0, high = m;
        int half = (m + n + 1) / 2;  // size of the combined left half

        while (low <= high) {
            int i = low + (high - low) / 2;   // partition index in nums1
            int j = half - i;                 // forced partition index in nums2

            int nums1_left  = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1_right = (i == m) ? INT_MAX : nums1[i];
            int nums2_left  = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2_right = (j == n) ? INT_MAX : nums2[j];

            if (nums1_left <= nums2_right && nums2_left <= nums1_right) {
                // Correct partition found
                if ((m + n) % 2 == 0) {
                    return (max(nums1_left, nums2_left) + min(nums1_right, nums2_right)) / 2.0;
                } else {
                    return max(nums1_left, nums2_left);
                }
            } else if (nums1_left > nums2_right) {
                high = i - 1;  // i too big, shrink left
            } else {
                low = i + 1;   // i too small, grow right
            }
        }

        return 0.0; // unreachable if inputs are valid sorted arrays
    }
};
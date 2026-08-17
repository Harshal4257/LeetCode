class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int m = 2*n;
        for(int i = n;i < m;i++) {
            nums.push_back(nums[i - n]);
        }
        return nums;
    }
};
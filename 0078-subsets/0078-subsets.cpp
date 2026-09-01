class Solution {
public:
    void subsets(vector<int>& nums, vector<int>& ans, vector<vector<int>>& allSubsets, int i) {
        if(i == nums.size()) {
            allSubsets.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        subsets(nums, ans, allSubsets, i + 1);

        ans.pop_back();
        subsets(nums, ans, allSubsets, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        subsets(nums, ans, allSubsets, 0);
        return allSubsets;
    }
};
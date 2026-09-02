class Solution {
   public:
    void subsets(vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& combin,
                 int i) {
        if (target == 0) {
            ans.push_back(combin);
            return;
        }
        for (int x = i; x < nums.size(); x++) {
            if (nums[x] > target) break;
            if (x > i && nums[x] == nums[x - 1]) continue;
            combin.push_back(nums[x]);
            subsets(nums, target - nums[x], ans, combin, x + 1);
            combin.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> combin;
        subsets(nums, target, ans, combin, 0);
        return ans;
    }
}
;

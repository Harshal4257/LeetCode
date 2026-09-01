class Solution {
public:
    set<vector<int>> st;

    void subsets(vector<int>& nums, vector<vector<int>>& ans, vector<int> combin, int target, int i) {
        if(i == nums.size() || target < 0) return;
        if(target == 0) {
            if(st.find(combin) == st.end()) {
                ans.push_back(combin);
                st.insert(combin);
            }
            return;
        }

        combin.push_back(nums[i]);
        subsets(nums, ans, combin, target - nums[i], i + 1);
        subsets(nums, ans, combin, target - nums[i], i);

        combin.pop_back();
        subsets(nums, ans, combin, target, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        subsets(nums, ans, combin, target, 0);
        return ans;
    }
};
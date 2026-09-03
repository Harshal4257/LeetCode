class Solution {
public:
    vector<vector<int>> ans;
    vector<int> combin;
    set<vector<int>> st;
    void subsets(vector<int>& nums, int level) {
        if(level == nums.size()) {
            if(!st.count(combin)) {
                ans.push_back(combin);
                st.insert(combin);
            }
            return;
        }

        combin.push_back(nums[level]);
        subsets(nums, level + 1);

        combin.pop_back();
        subsets(nums, level + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        subsets(nums, 0);
        return ans;
    }
};

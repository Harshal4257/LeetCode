class Solution {
public:
vector<vector<int>> ans;
    void getperm(vector<int>& nums, int ind) {
        if(nums.size() == ind) {
            ans.push_back({nums});
            return;
        }
        unordered_set<int> st;

        for(int i  = ind;i < nums.size();i++) {
            if(st.count(nums[i])) continue;
            st.insert(nums[i]);
            swap(nums[ind], nums[i]);
            getperm(nums, ind + 1);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        getperm(nums, 0);
        return ans;
    }
};

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left = 0;
        int maxcount = 0;
        for(int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;
            while(mp[nums[right]] > k) {
                mp[nums[left]]--;
                left++;
            }
            maxcount = max(maxcount, right - left + 1);
        }
        return maxcount;
    }
};
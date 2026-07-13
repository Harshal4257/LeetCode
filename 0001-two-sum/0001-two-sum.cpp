class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sum;
        for(int x = 0;x<nums.size();x++){
            int more = target - nums[x];
            if(sum.count(more)){
                return {sum[more],x};
            }
            sum[nums[x]] = x;
        }
    return {};
    }
};
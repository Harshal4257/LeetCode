class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int majorityElem = nums[0], maxCount = 0;
        for(int i : nums){
            mp[i]++;
            if(mp[i] > maxCount){
                maxCount = mp[i];
                majorityElem = i;   // remember WHICH element had this count
            }
        }
        return majorityElem;
    }
};
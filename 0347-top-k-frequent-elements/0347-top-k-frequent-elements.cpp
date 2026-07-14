class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto x:nums) mp[x]++;

        vector <vector<int>> buckets(n+1);
        for(auto& [elements, count] : mp) buckets[count].push_back(elements);

        vector<int> result;
        for(auto i=n;i>=0;i--){
            for(int element:buckets[i]){
                result.push_back(element);
                if(result.size() == k) return result;
            }
        }
        return result;
    }
};